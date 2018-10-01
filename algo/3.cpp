class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i, j;
        string temp;
        for(i = 0; i < s.length(); i++) {
            temp = s[i];
            for(j = i+1; j < s.length(); j++) {
                if(temp.find(s[j]) == string::npos)
                    temp.push_back(s[j]);
                else
                    break;
            }
            if(temp.length() > ans) {
                ans = temp.length();
                if(j == s.length()) {
                    break;
                }
            }
        }
        // cout<<"ANS IS "<<ans<<endl;
        return ans;
    }
};


// Sliding window approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0;
        unordered_set<char> SET;
        while(i < s.length() && j < s.length()) {
            if(SET.find(s[j]) == SET.end()) {
                // cout<<s[j]<<" inserted"<<endl;
                SET.insert(s[j++]);
                ans = ans > j - i ? ans : j - i;
            } else {
                // cout<<s[j]<<" removed"<<endl;
                SET.erase(s[i++]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> Map;
        int ans = 0;
        for(int j = 0, i = 0; j < s.length(); j++) {
            if(Map.find(s[j]) != Map.end()) {
                i = Map[s[j]] > i ? Map[s[j]] : i;
            }
            ans = ans > j - i + 1 ? ans : j - i + 1;
            Map[s[j]] = j + 1;
        }
        return ans;
    }
};
