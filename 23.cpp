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

// Sol2 O(n logk)
class Solution {
    ListNode *dummy, *temp;
    ListNode *merge(ListNode *list1, ListNode *list2) {
        dummy -> next = nullptr;
        temp = dummy;
        
        while (list1 && list2) {
            if (list1 -> val < list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            } else {
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }
        
        if (!list2)
            temp -> next = list1;
        else
            temp -> next = list2;
        
        return dummy -> next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        
        dummy = new ListNode(-100);
        ListNode *list1, *list2;
        
        int step = 1;
        while (step < lists.size()) {
            // cout << "step is: " << step << endl;
            for (int i = 0; i < lists.size() && i + step < lists.size(); i += 2*step) {
                // cout << "\t i is: " << i << endl;
                list1 = lists[i];
                list2 = lists[i+step];
                
                lists[i] = merge(list1, list2);
            }
            step *= 2;
        }
        return lists[0];
    }
};

// Sol1 O(kn)
/*
class Solution {
    ListNode *dummy, *temp;
    ListNode *merge(ListNode *list1, ListNode *list2) {
        dummy -> next = nullptr;
        temp = dummy;
        
        while (list1 && list2) {
            if (list1 -> val < list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            } else {
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }
        
        if (!list2)
            temp -> next = list1;
        else
            temp -> next = list2;
        
        return dummy -> next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        
        dummy = new ListNode(-100);
        ListNode *list1, *list2;
        
        while (lists.size() > 1) {
            list1 = lists[lists.size()-1];
            lists.pop_back();
            list2 = lists[lists.size()-1];
            lists.pop_back();
            
            lists.push_back(merge(list1, list2));
        }
        return lists[0];
    }
};
*/
