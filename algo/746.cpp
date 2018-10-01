#define NIL -199
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp_table(n+1, NIL);
        dp_table[n] = 0;
        dp_table[n-1] = cost[n-1];
        for(int i = n - 2; i >= 0; i--) {
            dp_table[i] = cost[i] + min(dp_table[i+1], dp_table[i+2]);
        }
        for(int i = 0; i <= n; i++) {
            cout<<dp_table[i]<<" ";
        }
        cout<<endl;
        return min(dp_table[0], dp_table[1]);
    }
};
