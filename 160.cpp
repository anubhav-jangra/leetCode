/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Sol3, O(max(m,n)) time, O(1) space

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) // if any of the two is null ptr
            return nullptr;
        
        ListNode *tempA = headA, *tempB = headB, *endA = nullptr, *endB = nullptr;
        
        while (true) {
            if (tempA == tempB)
                return tempA;
            
            if (tempA->next) {
                tempA = tempA -> next;
            } else {
                endA = tempA;
                tempA = headB;
                if (endB && endB != endA) // if endB has occured, and it is not equal to endA, then no intersection
                    return nullptr;
            }
            
            if (tempB->next) {
                tempB = tempB -> next;
            } else {
                endB = tempB;
                tempB = headA;
                if (endA && endA != endB) // if endA has occured, and it is not equal to endB, then no intersection
                    return nullptr;
            }
        }
    }
};


// Sol2, O(max(m,n)) time, O(1) space
/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) // if any of the two is null ptr
            return nullptr;
        
        int len1 = 0, len2 = 0;
        ListNode *tempA = headA, *tempB = headB;
        while (tempA->next) {
            tempA = tempA -> next;
            len1++;
        }
        while (tempB->next) {
            tempB = tempB -> next;
            len2++;
        }
        if (tempB != tempB) // if both the lists have different end nodes, then they are intersecting at any point
            return nullptr;
        
        // if list headA is bigger, walk it to make it of equal length
        if (len1 > len2) {
            for (int i = 0; i < len1-len2; i++)
                headA = headA -> next;
        } else {
            for (int i = 0; i < len2-len1; i++)
                headB = headB -> next;
        }
        while (headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};
*/

// Sol1, O(mn) time complexity, O(1) space complexity
/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp;
        while (headA && headB) {
            if (headA == headB)
                return headA;
            else if (headA == headB -> next)
                return headA;
            else if (headA -> next == headB)
                return headB;
            headA = headA -> next;
            headB = headB -> next;
        }
        return nullptr;
    }
};
*/
