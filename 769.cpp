class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int span = 0, curr;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= i) 
                curr = i;
            else
                curr = arr[i];
            
            // now compare the two pairs
            if (curr > span)
                span = curr;
            
            // check if condition for new chunk detected has been met
            if (span == i)
                ans++;
        }
        return ans;
    }
};

// Sol1
// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int ans = 0;
//         pair<int, int> span, curr;
//         span = pair<int, int>(0,0);
//         for (int i = 0; i < arr.size(); i++) {
//             if (arr[i] <= i) 
//                 curr = pair<int, int>(arr[i], i);
//             else
//                 curr = pair<int, int>(i, arr[i]);
            
//             // now compare the two pairs
//             if (curr.second > span.second)
//                 span.second = curr.second;
            
//             // check if condition for new chunk detected has been met
//             if (span.second == i)
//                 ans++;
//         }
//         return ans;
//     }
// };
