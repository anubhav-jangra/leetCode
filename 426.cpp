/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// Sol2 O(n) time, O(h) space h: tree height
class Solution {
    
Node *prev_node;
void recurse(Node *root) { // lr_val 0: left, 1: root
    
    if (root -> left) recurse(root -> left);
    
    if (prev_node) {
        prev_node -> right = root;
        root -> left  = prev_node;
    }
    prev_node = root;
    
    if (root -> right) recurse(root -> right);
}
public:
    Node* treeToDoublyList(Node* root) {
        
        if (!root) return nullptr;

        prev_node = nullptr;
        recurse(root);

        while (prev_node -> left) 
            prev_node = prev_node -> left;
        
        if (!root) return nullptr;
        Node *temp = prev_node;
        
        // making it circular
        while (temp -> right)
            temp = temp -> right;
        
        prev_node -> left = temp;
        temp -> right = prev_node;
        
        return prev_node;
    }
};

// Sol2 O(n^2) time, O(h) space h: tree height
/*
class Solution {
    
    // this util function assums that root is not null!
    Node *recurse(Node *root, bool lr_val) { // lr_val 0: left, 1: root
        // cout << root -> val << " ";
        if (root -> left) {
            Node *l_node = recurse(root -> left, false);
            l_node -> right = root;
            root -> left = l_node;
        }

        if (root -> right) {
            Node *r_node = recurse(root -> right, true);
            root -> right = r_node;
            r_node -> left = root;
        }

        Node *temp = root;
        // return wisely
        if (lr_val) { // right, hence return the beginning of the DLL
            while (temp -> left) 
                temp = temp -> left;
            return temp;
        } else { // left, hence return the end of the list
            while (temp -> right)
                temp = temp -> right;
            return temp;
        }
    }

public:
    Node* treeToDoublyList(Node* root) {
        
        if (!root) return nullptr;
        Node *temp, *ans = recurse(root, true); // since we need beginning of the DLL, we chose the right setting ;)
        // ans is a DLL, but it is not circular
        temp = ans;
        
        // making it circular
        while (temp -> right)
            temp = temp -> right;
        
        ans -> left = temp;
        temp -> right = ans;
        
        return ans;
    }
};
*/
