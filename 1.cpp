class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int a = 0;
        for(int i = 0; i < nums.size(); i++) {
            a = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                if(a + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> mapp;     // could have also used unordered_map
        for(int i = 0; i < nums.size(); i++) 
            mapp.insert(make_pair(nums[i], i));
        for(int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            map<int, int>::iterator itr = mapp.find(compliment);    // also must change here if using unordered map
            if(itr != mapp.end() && itr -> second != i) {
                ans.push_back(i);
                ans.push_back(itr->second);
                return ans;
            }
        }
    }
};
