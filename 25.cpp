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

// The recursive solution with O(n) space for stack
class Solution {
    ListNode *successor;
    int init_k, i;
    ListNode* func(ListNode* head, int k) {
        if (!head || !head -> next) {
            return head;
        }
        if (k == 1) {
            // check if next k elements are possible, if not, then just set successor to head
            successor = head -> next;
            for (i = 0; i < init_k && successor; i++)
                successor = successor -> next;
            
            if (!successor && i < init_k)
                successor = head -> next;
            else
                successor = func(head -> next, init_k);
            return head;
        }

        ListNode *temp = func(head->next, k-1);
        head -> next -> next = head;
        head -> next = successor;
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        init_k = k;
        return func(head, k);
    }
};


// The iterative solution with constant space
/*
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr1, *ptr2, *ptr3, *temp, *dummy_head = new ListNode(-100, head);
        head = dummy_head;
        int i;
        
        while (head -> next) {
            ptr1 = nullptr; // pointing to the reversed array;
            ptr2 = head -> next; // reverse next k elements 
            
            // have a check if k values are there ahead
            for (i = 0; i < k && ptr2; i++)
                ptr2 = ptr2 -> next;

            if (!ptr2 && i < k)
                break;
            
            ptr2 = head -> next;
            for (i = 0; i < k; i++) {
                temp = ptr2 -> next;
                if (!ptr1)
                    ptr3 = ptr2;
                ptr2 -> next = ptr1;
                ptr1 = ptr2;
                ptr2 = temp;
            }
            
            head -> next = ptr1;
            ptr3 -> next = temp;
            head = ptr3;
        }
        
        return dummy_head->next;
    }
};
*/