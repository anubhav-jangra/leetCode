// Sol2 O(n*k) time, O(n) space (Recursion) (top down approach) (got passed by patching stuff up badly!)
class Solution {
private:
    vector<int> dp;
    int recurse(vector<int>& coins, int amount) {
        
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (dp[amount] != -1) return dp[amount];
        
        int temp, min_val = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            temp = recurse(coins, amount - coins[i]);
            if (temp != -1 && temp < min_val)
                min_val = 1+temp;
        }
        // if (min_val != INT_MAX)
        dp[amount] = min_val;
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, -1);
        dp[0] = 0;
        int ans = recurse(coins, amount);
        if (ans == INT_MAX)
            return -1;
        return (ans == -1) ? -1 : ans;
    }
};


// Sol2 O(n*k) time, O(n) space (Tabularization) (bottom up approach)
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] >= 0 && dp[j-coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
            }
        }
        
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};
*/

// Sol1 O(n*k) time, O(n*k) space
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, INT_MAX));
        
        for (int i = 0; i < coins.size(); i++)
            dp[i][0] = 0;
        
        
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                
                if (j - coins[i] >= 0 && dp[i][j-coins[i]] != INT_MAX)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j-coins[i]]);
                
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
        }
        
        if (dp[coins.size()-1][amount] == INT_MAX)
            return -1;
        return dp[coins.size()-1][amount];
    }
};
*/

