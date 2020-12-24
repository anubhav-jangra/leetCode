class Solution {
public:
    int reverse(int x) {
        int k = 0;
        int digits = 0, temp = x;
        while(temp != 0) {
            digits += 1;
            temp /= 10;
        }
        temp = x;
        int t = 1;
        for(int i = 1; i < digits; i++)
            t *= 10;
        while(temp != 0) {
            if(abs(k + (temp % 10) * (long long)t) > 2147483648) {
                return 0;
            }
            k += (temp % 10) * t;
            temp /= 10;
            t /= 10;
        }
        return k;
    }
};
