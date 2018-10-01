class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= 1) {
            return s;
        }
        if (numRows == 1) {
            return s;
        }
        string ans = "";
        int d = numRows * 2 - 2;
        for(int i = 0; i < numRows; i++) {
            int temp = i;
            if(i == 0 || i == numRows - 1) {
                while(temp < s.length()) {
                    ans.push_back(s[temp]);
                    temp += d;
                }
            } else {
                while(temp < s.length()) {
                    ans.push_back(s[temp]);
                    if (temp + (2*(numRows - i) - 2) < s.length()){
                        ans.push_back(s[temp + (2*(numRows - i) - 2)]);
                    }
                    temp += d;
                }
            }
        }
        return ans;
    }
};
