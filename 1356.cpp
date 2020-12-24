class Solution {
    int count_(int n) {
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        while(n != 1) {
            if (n & 1)
                ans += 1;
            n = n>>1;
        }
        return ans;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int> > vec;
        
        for (int i = 0; i < arr.size(); i++) {
            pair<int, int> pr(count_(arr[i]), arr[i]);
            vec.push_back(pr);
        }
        
        sort(vec.begin(), vec.end());
        
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = vec[i].second;
        }
        return arr;
    }
};
