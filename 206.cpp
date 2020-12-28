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

// Recursive approach - 2:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *temp = reverseList(head->next);
        head -> next -> next = head;
        head -> next = nullptr;
        return temp;
    }
};

// Recursive approach - 1:
/*
class Solution {
    ListNode *p1 = nullptr, *temp = nullptr;
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return p1;
        
        temp = head -> next;
        head -> next = p1;
        p1 = head;
        
        return reverseList(temp);
    }
};
*/

// Iterative approach:
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p1 = nullptr, *p2 = head, *temp = nullptr;
        while (p2) {
            temp = p2 -> next;
            p2 -> next = p1;
            p1 = p2;
            p2 = temp;
        }
        
        return p1;
    }
};
*/