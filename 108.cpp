/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode *recurse(vector<int> &arr, int l, int r) {
        if (l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(arr[mid]);
        node -> left  = recurse(arr, l, mid-1);
        node -> right = recurse(arr, mid+1, r);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *ans = recurse(nums, 0, nums.size()-1);
        return ans;
    }
};
