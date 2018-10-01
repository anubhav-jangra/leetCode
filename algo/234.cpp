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
    ListNode *front;
    bool isPalindrome(ListNode* head) {
        front = head;
        return foo(head);
        // ListNode *temp = head;
        // int n = 0;
        // while(temp != nullptr) {
        //     n += 1;
        //     temp = temp -> next;
        // }
        // temp = head;
        // ListNode *temp2;
        // for(int i = 0; i < n/2; i++) {
        //     temp2 = head;
        //     for(int j = 0; j < n - i - 1; j++) {
        //         temp2 = temp2 -> next;
        //     }
        //     if(temp -> val != temp2 -> val)
        //         return false;
        //     temp = temp -> next;
        // }
        // return true;
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
