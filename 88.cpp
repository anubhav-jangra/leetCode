class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m-1, idx2 = n-1, place=m+n-1;
        while (idx2 >= 0 && idx1 >= 0)
            if (nums1[idx1] >= nums2[idx2])
                nums1[place--] = nums1[idx1--];
            else
                nums1[place--] = nums2[idx2--];
        while (idx2 >= 0)
            nums1[place--] = nums2[idx2--];
    }
};

// Sol1: O(1) space, O((m+n)*n) Time (maybe!) (naah, the time was same as above, maybe test cases are small here)
/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = 0, idx2 = 0;
        while (idx2 < n) {
            if (idx1 == m+idx2) {
                for (int i = idx1; i < m+n; i++)
                    nums1[i] = nums2[idx2++];
            }
            else if (nums1[idx1] <= nums2[idx2]) {
                idx1++;
            } else {
                for (int j = m+n-1; j >= idx1 + 1; j--)
                    nums1[j] = nums1[j-1];
                nums1[idx1++] = nums2[idx2++];
            }
        }
    }
};
*/
