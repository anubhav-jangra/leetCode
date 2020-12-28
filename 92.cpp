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

// Sol2 one pass
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *temp, *dummy_head = new ListNode(-100, head), *ptr1 = nullptr, *ptr2 = nullptr, *temp2, *temp3;
        temp = dummy_head;
        
        // finding element after which we need to begin reversing
        for (int i = 1; i < m; i++)
            temp = temp -> next;
        
        ptr2 = temp -> next;
        for (int i = m; i <= n; i++) {
            temp2 = ptr2 -> next;
            if (!ptr1) {
                temp3 = ptr2;
            }
            ptr2 -> next = ptr1;
            ptr1 = ptr2;
            ptr2 = temp2;
        }
        
        temp -> next = ptr1;
        temp3 -> next = temp2;
        
        return dummy_head -> next;
    }
};

// Sol1 almost one pass
/*
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *temp, *dummy_head = new ListNode(-100, head), *ptr1 = nullptr, *ptr2 = nullptr, *temp2;
        temp = dummy_head;
        
        // finding element after which we need to begin reversing
        for (int i = 1; i < m; i++)
            temp = temp -> next;
        
        ptr2 = temp -> next;
        for (int i = m; i <= n; i++) {
            temp2 = ptr2 -> next;
            ptr2 -> next = ptr1;
            ptr1 = ptr2;
            ptr2 = temp2;
        }
        
        temp -> next = ptr1;
        while (ptr1 -> next) {
            ptr1 = ptr1 -> next;
        }
        
        ptr1 -> next = temp2;
        
        return dummy_head -> next;
    }
};
*/
