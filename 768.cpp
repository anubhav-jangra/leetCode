// An O(n) solution, with O(n) space
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> min_arr(arr.size(), 0), max_arr(arr.size(), 0);
        
        // creating a cumulative min array that has min of all elements from arr[k] to arr[end] at kth position
        min_arr[arr.size()-1] = arr[arr.size()-1];
        for(int i = arr.size()-2; i >= 0; i--)
            min_arr[i] = min(min_arr[i+1], arr[i]);
        
        // creating a cumulative max array that has max of all elements from arr[0] to arr[k] at kth position
        max_arr[0] = arr[0];
        for(int i = 1; i < arr.size(); i++)
            max_arr[i] = max(max_arr[i-1], arr[i]);
        
        int ans = 1;
        for (int i = 1; i < arr.size(); i++) {
            // check if condition for new chunk detected has been met
            if (min_arr[i] >= max_arr[i-1])
                ans++;
        }
        return ans;
    }
};

// Sol1: O(n2), practically less than that, but worst case O(n2)
// However, this solution is O(1) extra space solution
/*
class Solution {
    int find_pos(vector<int> &arr, int idx) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == arr[idx] && i < idx)
                count++;
            if (arr[i] < arr[idx])
                count++;
        }
        return count;
    }
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int start = 0, span = 0, curr, pos;
        for (int i = 0; i < arr.size(); i++) {
            pos = i;
            if (arr[i] >= arr[start])
                pos = find_pos(arr, i);
            if (pos <= i)
                curr = i;
            else
                curr = pos;
            
            // now compare the two pairs
            if (curr > span)
                span = curr;
            
            // check if condition for new chunk detected has been met
            if (span == i) {
                ans++;
                start = i+1;
            }
        }
        return ans;
    }
};
*/
