/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr)
            return 0;
        bfs(root, 0);
        return max_depth+1;
    }
private:
    int max_depth = 0;
    void bfs(Node* root, int depth) {
        if(depth > max_depth)
            max_depth = depth;
        for(int i = 0; i < root->children.size(); i++) {
            bfs(root->children[i], depth + 1);
        }
    }
};
