class Solution {
public:
    int orangesRotting(vector<vector<int> > &grid) {
        
        int R = grid.size(), C = grid[0].size();
        int i, j, ans = -1;
        
        // check for all empty grid edge case
        bool marker = true;
        for (i = 0; i < R; i++)
            for (j = 0; j < C; j++)
                if (grid[i][j] != 0)
                    marker = false;
        if (marker)
            return 0;
        
        vector<vector<int> > rotSheet = grid; // to store the current updates
        queue<pair<int, int> > rotten;

        // add the already rotten 
        for (i = 0; i < R; i++)
            for (j = 0; j < C; j++)
                if (grid[i][j] == 2) 
                    rotten.push(make_pair(i, j));

        while (!rotten.empty()) {

            rotten.push(make_pair(-1, -1)); // a delimiter notifying that new time stamp will take place from this point onwards
            ans++;

            while (rotten.front() != pair<int, int>(-1, -1)) {
                // rot the nearby oranges in a BFS manner

                i = rotten.front().first;
                j = rotten.front().second;
                // cout << "<" << i << ", " << j << ">\n";
                rotten.pop();

                // check left
                if (i-1 >= 0 && rotSheet[i-1][j] == 1) {
                    rotSheet[i-1][j] = 2;
                    rotten.push(make_pair(i-1, j));
                }

                // check right
                if (i+1 < R && rotSheet[i+1][j] == 1) {
                    rotSheet[i+1][j] = 2;
                    rotten.push(make_pair(i+1, j));
                }

                // check up
                if (j-1 >= 0 && rotSheet[i][j-1] == 1) {
                    rotSheet[i][j-1] = 2;
                    rotten.push(make_pair(i, j-1));
                }

                // check bottom
                if (j+1 < C && rotSheet[i][j+1] == 1) {
                    rotSheet[i][j+1] = 2;
                    rotten.push(make_pair(i, j+1));
                }

            }

            // cout << "~~~~~~~~~\n";
            // remove the delimiter
            rotten.pop();
        }

        // check if there is any fresh orange left in the grid
        for (i = 0; i < R; i++)
            for (j = 0; j < C; j++)
                if (rotSheet[i][j] == 1)
                    return -1;

        return ans;
    }
};
