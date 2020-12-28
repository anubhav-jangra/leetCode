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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if (!head->next && n == 1)
        //     return nullptr;
        ListNode *p1 = new ListNode(-100, head), *p2;
        p2 = p1;
        for (int i = 0; i <= n; i++)
            p2 = p2 -> next;
        
        while (p2) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        if (p1 -> next == head)
            return p1 -> next -> next;
        p1 -> next = p1 -> next -> next;
        
        return head;
    }
};
