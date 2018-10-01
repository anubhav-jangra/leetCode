class Solution {
public:
    bool isPalindrome(string s){
        for(int i = 0; i < s.length() / 2 ; i++) {
            if(s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        for(int i = s.length(); i >= 0; i--) {
            for(int j = 0; j + i <= s.length(); j++) {
                string subStr = s.substr(j, i);
                if(isPalindrome(subStr)) {
                    return subStr;
                }
            }
        }
    }
};
