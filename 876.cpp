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

// Sol2 - One pass
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head -> next)
            return head;
        
        ListNode *temp1 = head, *temp2 = head;
        while (temp2) {
            if (temp2 -> next) {
                temp1 = temp1 -> next;
                temp2 = temp2 -> next -> next;
            }
            else 
                temp2 = temp2 -> next;
        }
        
        return temp1;
    }
};

// Sol1 - two pass
/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        int count = 0;
        ListNode *temp = head;
        while (temp) {
            count++; temp = temp -> next;
        }
        
        temp = head;
        for (int i = 0; i < ceil(count/2); i++)
            temp = temp -> next;
        
        return temp;
    }
};
*/
