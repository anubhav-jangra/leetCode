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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count = 0, i, j, extra;
        ListNode *temp = root, *temp2;
        while (temp) {
            count++;
            temp = temp -> next;
        }
        vector<ListNode*> ans;
        extra = count % k;
        for (j = 0; j < k; j++) {
            temp = root;
            for (i = 1; i < count/k; i++) {
                root = root -> next;
            }
            if (extra > 0) {
                if (count/k != 0)
                    root = root -> next;
                extra--;
            }
            if (root) {
                temp2 = root -> next;
                root -> next = nullptr;
                root = temp2;
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};
