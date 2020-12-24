class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int counter = 0;
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            if (counter == target.size())
                return ans;
            if (i == target[counter]) {
                ans.push_back("Push");
                counter++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
