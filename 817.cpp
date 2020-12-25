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
vector<bool> vec(10000, false);
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        
        // initialize vec to false in the beginning for once
        for (int i = 0; i < 10000; i++)
            vec[i] = false;
        // set vec according to G
        for (int i = 0; i < G.size(); i++) {
            vec[G[i]] = true;
        }
        
        int ans = G.size();
        while (head->next) {
            if (vec[head->val] && vec[head->next->val]) {
                ans--;
                head = head -> next;
                // check if this is in continuation of previous componenet
                while (head -> next && vec[head->val] && vec[head->next->val]) {
                    ans--;
                    head = head -> next;
                }
            }
            if (head -> next)
                head = head -> next;
        }
        
        return ans;
    }
};

// Sol1
/*
class Solution {
    int a_idx, b_idx;
    bool exists(vector<int> &G, int a, int b) {
        bool a_ = false, b_ = false; // can be removed by utilizing/initializing a_idx, b_idx (with -1)
        for (int i = 0; i < G.size(); i++) {
            if (G[i] == a)
                a_ = true;
            else if (G[i] == b)
                b_ = true;
            if (a_ && b_)
                return true;
        }
        return false;
    }
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int ans = G.size();
        while (head->next) {
            if (exists(G, head->val, head->next->val)) {
                ans--;
                head = head -> next;
                // check if this is in continuation of previous componenet
                while (head -> next && exists(G, head->val, head->next->val)) {
                    ans--;
                    head = head -> next;
                }
            }
            if (head -> next)
                head = head -> next;
        }
        
        return ans;
    }
};*/
