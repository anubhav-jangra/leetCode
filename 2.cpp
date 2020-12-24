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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode *head = nullptr, *temp = nullptr;
        while(l1 != nullptr && l2 != nullptr) {
            sum = (l1 -> val) + (l2 -> val) + carry;
            if(head == nullptr) {
                head = new ListNode(sum % 10);
                temp = head;
            } else {
                temp -> next = new ListNode(sum % 10);
                temp = temp -> next;
                cout<<temp -> val<<" ";
            }
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == nullptr) {
            while(l2 != nullptr) {
                sum = l2 -> val + carry;
                temp -> next = new ListNode(sum % 10);
                temp = temp->next;
                carry = sum / 10;
                l2 = l2 -> next;
            }
        } else {
            while(l1 != nullptr) {
                sum = l1 -> val + carry;
                temp -> next = new ListNode(sum % 10);
                temp = temp->next;
                carry = sum / 10;
                l1 = l1 -> next;
            }
        }
        while(carry != 0) {
            sum = carry;
            temp -> next = new ListNode(sum % 10);
            temp = temp->next;
            carry = sum / 10;
        }
        // while(l1 != nullptr) {
        //     num1 += (l1->val) * tens;
        //     tens *= 10;
        //     l1 = l1->next;
        // }
        // tens = 1;
        // while(l2 != nullptr) {
        //     num2 += (l2->val) * tens;
        //     tens *= 10;
        //     l2 = l2->next;
        // }
        // int sum = num1 + num2;
        // ListNode *ans = nullptr, *temp = nullptr, *head;
        // while(sum > 0) {
        //     temp = ans;
        //     ans = new ListNode(sum % 10);
        //     if(temp != nullptr) {
        //         while(temp -> next != nullptr)
        //             temp = temp->next;
        //         temp -> next = ans;
        //     } else {
        //         head = ans;
        //     }
        //     sum /= 10;
        // }
        return head;
    }
};
