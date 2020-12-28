/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// latest solution
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode *ptr1 = new ListNode(-100, head), *ptr2;
        ptr2 = ptr1;
        
        // find the middle of the linked list
        while (ptr2) {
            if (ptr2 -> next) {
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next -> next;
            } else {
                ptr2 = ptr2 -> next;
            }
        }
        
        // reverse the second half of the list 
        ListNode *temp;
        ptr1 = ptr1 -> next;
        ptr2 = nullptr; // store the reversed end part of array
        while (ptr1) {
            temp = ptr1 -> next;
            ptr1 -> next = ptr2;
            ptr2 = ptr1;
            ptr1 = temp;
        }
        
        ptr1 = head;
        while (ptr2) {
            if (ptr1 -> val != ptr2 -> val)
                return false;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return true;
    }
};

// Old solution-2 from 2017/18
/*
class Solution {
public:
    ListNode *front;
    bool isPalindrome(ListNode* head) {
        front = head;
        return foo(head);
    }

    bool foo(ListNode *tail) {
        if(tail == nullptr)
            return true;
        if(foo(tail->next) && tail->val == front->val) {
            front = front->next;
            return true;
        }
        return false;
    }
};
*/

// Old solution-2 from 2017/18 (V.v. bad time:/)
/*
class Solution {
public:
    ListNode *front;
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
        int n = 0;
        while(temp != nullptr) {
            n += 1;
            temp = temp -> next;
        }
        temp = head;
        ListNode *temp2;
        for(int i = 0; i < n/2; i++) {
            temp2 = head;
            for(int j = 0; j < n - i - 1; j++) {
                temp2 = temp2 -> next;
            }
            if(temp -> val != temp2 -> val)
                return false;
            temp = temp -> next;
        }
        return true;
    }
};
*/