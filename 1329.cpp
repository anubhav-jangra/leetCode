class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        
        // cout<<"input matrix"<<endl;
        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < col; j++) {
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        // work on diagonals starting with row 0
        for (int i = 0; i < col - 1; i++) {
            vector<int> temp;
            for (int k = 0; k < min(row, col); k++) {
                if (k < row and i+k < col) {
                    temp.push_back(mat[k][i+k]);
                }
            }
            
            sort(temp.begin(), temp.end());
            
            for (int k = 0; k < temp.size(); k++) {
                mat[k][i+k] = temp[k];
            }
        }
        
        // cout<<"matrix after step1"<<endl;
        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < col; j++) {
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        // work on diagonals starting with col 0
        for (int i = 1; i < row - 1; i++) {
            vector<int> temp;
            for (int k = 0; k < min(row, col); k++) {
                if (k < col and i+k < row) {
                    temp.push_back(mat[i+k][k]);
                }
            }
            sort(temp.begin(), temp.end());
        
            for (int k = 0; k < temp.size(); k++) {
                mat[i+k][k] = temp[k];
            }
        }
        
        // cout<<"final matrix"<<endl;
        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < col; j++) {
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return mat;
    }
};
