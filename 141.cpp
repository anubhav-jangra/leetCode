/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr1 = head, *ptr2 = head;
        do {
            if (!ptr2 || !(ptr2 -> next))
                return false;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next -> next;
        } while (ptr1 != ptr2);
        return true;
    }
};
