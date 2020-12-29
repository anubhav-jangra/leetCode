class Solution {
    bool crush_flag;
    void reset_arr(vector<vector<bool>> &arr) {
        for (int i = 0; i < arr.size(); i++)
            for (int j = 0; j < arr[0].size(); j++)
                arr[i][j] = false;
    }
    
    bool can_crush(vector<vector<int>>& board, vector<vector<bool>> &arr) {
        crush_flag = false; // default setup
            
        int prev_val = 0;
        int start_counter = 0, end_counter = 0;
        // find row-wise crushings
        for (int i = 0; i < board.size(); i++) {
            prev_val = 0; start_counter = 0; end_counter = 0; // reset each time
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 0) {
                    prev_val = board[i][j]; start_counter = j; end_counter = j;
                    continue;
                }
                if (board[i][j] != prev_val) {
                    prev_val = board[i][j]; start_counter = j; end_counter = j;
                } else {
                    end_counter++;
                }
                // check if there was anything crushworthy in this row
                if (end_counter - start_counter == 2) {
                    crush_flag = true;
                    arr[i][start_counter]   = true;
                    arr[i][start_counter+1] = true;
                    arr[i][start_counter+2] = true;
                } else if(end_counter - start_counter > 2) {
                    arr[i][end_counter] = true;
                }
            }
        }
        
        // find column-wise crushings
        for (int j = 0; j < board[0].size(); j++) {
            prev_val = 0; start_counter = 0; end_counter = 0; // reset each time
            for (int i = 0; i < board.size(); i++) {
                if (board[i][j] == 0) {
                    prev_val = board[i][j]; start_counter = j; end_counter = j;
                    continue;
                }
                
                if (board[i][j] != prev_val) {
                    prev_val = board[i][j]; start_counter = i; end_counter = i;
                } else {
                    end_counter++;
                }
                // check if there was anything crushworthy in this row
                if (end_counter - start_counter == 2) {
                    crush_flag = true;
                    arr[start_counter][j]   = true;
                    arr[start_counter+1][j] = true;
                    arr[start_counter+2][j] = true;
                } else if (end_counter - start_counter > 2) {
                    arr[end_counter][j] = true;
                }
            }
        }
        
        return crush_flag;
    }
    
    void fix_board(vector<vector<int>>& board) {
        int top, bottom;
        for (int j = 0; j < board[0].size(); j++) {
            top = -1; bottom = -1;
            for (int i = board.size()-1; i >= 0; i--) {
                if (board[i][j] == 0) {
                    if (top == -1) {
                        top = i; bottom = i;
                    } else {
                        top--;
                    }
                } else {
                    if (top == -1)
                        continue;
                    board[bottom--][j] = board[i][j];
                    board[i][j] = 0; top = i;
                }
            }
        }
    }
        
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        vector<vector<bool>> arr(board.size(), vector<bool> (board[0].size(), false));
        while(can_crush(board, arr)) {
            // code to crush
            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < arr[0].size(); j++) {
                    if (arr[i][j])
                        board[i][j] = 0;
                }
            }
            // code to reset the board (make candies rain<fall>!!)
            fix_board(board);
            
            // cout << "Board is: \n";
            // for (int i = 0; i < arr.size(); i++) {
            //     for (int j = 0; j < arr[0].size(); j++) {
            //         cout << board[i][j] << "\t";
            //     }
            //     cout << "\n";
            // }
            
            // reset the arr
            reset_arr(arr);
        }
        return board;
    }
};
