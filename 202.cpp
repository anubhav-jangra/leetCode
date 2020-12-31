// Sol2 O(1) space
class Solution {
    int foo(int x) {
        int k, ans = 0;
        while (x >= 10) {
            k = x % 10;
            x = x / 10;
            ans += k * k;
        }
        return ans + x * x;
    }
public:
    bool isHappy(int n) {
        int n1 = n;
        
        while (true) {
            n = foo(n);
            n1 = foo(foo(n1));
            
            if (n1 == 1)
                return true;
            else if (n1 == n)
                return false;
        }
    }
};

// Sol1 (using hasmaps) O(logn) space
/*
class Solution {
    int foo(int x) {
        int k, ans = 0;
        while (x >= 10) {
            k = x % 10;
            x = x / 10;
            ans += k * k;
        }
        return ans + x * x;
    }
public:
    bool isHappy(int n) {
        unordered_map<int, bool> mp;
        
        while (true) {
            if (mp.find(n) == mp.end())
                mp.insert(pair<int, bool> (n, true) );
            else
                return false;
            
            n = foo(n);
            if (n == 1)
                return true;
        }
    }
};
*/
