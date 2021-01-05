class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int end, total_count = accumulate(count.begin(), count.end(), 0), median_marker;
        long long int sum = 0;
        median_marker = ceil(total_count/2.0);
        double min_ele = -1, max_ele = -1, mode = 0, median = -1;
        for (int i = 0; i < count.size(); i++) {
            if (min_ele == -1 && count[i] > 0) {
                min_ele = i;
            }
            
            if (count[i] > 0 && max_ele < i) {
                max_ele = i;
            }
            
            sum += i * count[i];
            
            if (count[mode] < count[i]) {
                mode = i;
            }
            
            if (median_marker - count[i] <= 0 && median == -1) {
                if (total_count % 2 == 0) { // two medians
                    if (median_marker - count[i] == 0) {
                        int j = i+1;
                        while (count[j] == 0)
                            j++;
                        median = (i+j)/2.0;
                    } else {
                        median = i;
                    }
                } else { // only one median
                    median = i;
                }
            } else {
                median_marker -= count[i];
            }
        }
        
        vector<double> ans;
        ans.push_back(min_ele);
        ans.push_back(max_ele);
        ans.push_back(sum / (double) total_count);
        ans.push_back(median);
        ans.push_back(mode);
        
        return ans;
    }
};
