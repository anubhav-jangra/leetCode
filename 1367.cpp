/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode *root, ListNode* node) {
        if (!node) return true;
        if (!root) return false;
        return (root->val == node->val) && (check(root->left, node->next) || check(root->right, node->next));
    }
    
    bool DFS(TreeNode *root, ListNode* node) {
        if (!root) return false;
        
        // perform simple DFS steps
        return check(root, node) || DFS(root -> left, node) || DFS(root -> right, node);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return DFS(root, head);
    }
};

// Sol1
/*
class Solution {
    bool ans;
    ListNode *dummy_head;
    void DFS(TreeNode *root, ListNode* node) {
        if (ans)
            return;
        
        // check if either this node is the current node in the linked list
        if (root -> val == node -> val) // move ahead if it is
            node = node -> next;
        else // else reset to the first dummy
            node = dummy_head;
        
        if (node == nullptr) {
            ans = true;
            return;
        }
        
        // perform simple DFS steps
        if (root -> left)
            DFS(root -> left, node);
        if (root -> right)
            DFS(root -> right, node);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        dummy_head = head; // a dummy head
        ans = false;
        // DFS(root, dummy_head);
        // return ans;
        if(root == nullptr) {
            return false;
        }
        DFS(root, head);
        if(ans) return true;
        isSubPath(head, root->left);
        if(ans) return true;
        isSubPath(head, root->right);
        if(ans) return true;
        return false;
    }
};
*/
