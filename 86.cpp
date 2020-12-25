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
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp, *p1, *p2, *ans;
        ans = new ListNode(-1, head);
        p1 = ans;
        p2 = ans;
        
        // first travesre forward to find the first 'bigger than target value'
        while (p2 -> next && p2 -> next -> val < x) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        while (p2 -> next) {
            if (p2 -> next -> val < x) {
                temp = p2 -> next -> next;
                p2 -> next -> next = p1 -> next;
                p1 -> next = p2 -> next;
                p2 -> next = temp;
                p1 = p1 -> next;
            } else {
                p2 = p2 -> next;
            }
        }
        return ans -> next;
    }
};
