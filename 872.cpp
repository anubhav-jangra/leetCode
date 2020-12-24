/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        else if(root1 == nullptr || root2 == nullptr)
            return false;
        dfs1(root1);
        dfs2(root2);
        if(seq1.size() != seq2.size())
            return false;
        else {
            while(!seq1.empty()) {
                if(seq1.back() != seq2.back())
                    return false;
                seq1.pop_back();
                seq2.pop_back();
            }
        }
        return true;
    }
private:
    vector<int> seq1, seq2;
    void dfs1(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            seq1.push_back(root->val);
        else {
            if(root->left != nullptr)
                dfs1(root->left);
            if(root->right != nullptr)
                dfs1(root->right);
        }
    }
    void dfs2(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            seq2.push_back(root->val);
        else {
            if(root->left != nullptr)
                dfs2(root->left);
            if(root->right != nullptr)
                dfs2(root->right);
        }
    }
};
