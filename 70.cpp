#define NIL -199
class Solution {
public:
    vector<int> dp_table;
    int climbStairs(int n) {
        dp_table = vector<int>(n+1, NIL);
        return recurse(n);
    }
private:
    int recurse(int n) {
        if(n == 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        } else if(n == 2) {
            return 2;
        }
        if(dp_table[n-1] == NIL) {
            dp_table[n-1] = recurse(n-1);
        }
        if(dp_table[n-2] == NIL) {
            dp_table[n-2] = recurse(n-2);
        }
        dp_table[n] = dp_table[n-1] + dp_table[n-2];
        return dp_table[n];
    }
};
