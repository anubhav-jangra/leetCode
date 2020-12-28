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
    void reorderList(ListNode* head) {
        if (!(head) || !(head -> next) || !(head -> next -> next)) // size1 and size2 lists are already correct
            return;
        
        // find middle in one pass
        ListNode *ptr1 = new ListNode(-100, head), *ptr2;
        ptr2 = ptr1;
        while (ptr2) {
            if (ptr2 -> next) {
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next -> next;
            } else {
                ptr2 = ptr2 -> next;
            }
        }
        
        // cout << "middle is: " << ptr1 -> val;
        
        // reverse the second half of the list in one pass
        ListNode *temp = nullptr;
        ptr2 = nullptr; // stores the reversed array
        while (ptr1) {
            temp = ptr1 -> next;
            ptr1->next = ptr2;
            ptr2 = ptr1;
            ptr1 = temp;
        }
        
        // merge alternativly in an interweaving fashion
        ptr1 = head;
        while (ptr2 && ptr1) {
            temp = ptr1 -> next;
            ptr1 -> next = ptr2;
            ptr1 = temp;
            
            temp = ptr2 -> next;
            ptr2 -> next = ptr1;
            ptr2 = temp;
        }
    }
};
