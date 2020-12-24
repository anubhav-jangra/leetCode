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


// This solution is O(nlogn), and O(1) space
class Solution {
    int idx1, idx2;
    ListNode *iter, *thead;
    ListNode* merge(ListNode* list1, ListNode* list2, int len1, int len2) {
        // cout << "\tGiven list1: " << list1->val << " list2: " << list2->val << endl;
        // cout << "\tlen1: " << len1 << " len2: " << len2 << endl;
        idx1 = 0;
        idx2 = 0;
        thead = iter;
        while (idx1 < len1 && idx2 < len2) {
            if (list1 -> val < list2 -> val) {
                iter -> next = list1;
                iter  = iter -> next;
                list1 = list1 -> next;
                idx1++;
            } else {
                iter -> next = list2;
                iter  = iter -> next;
                list2 = list2 -> next;
                idx2++;
            }
        }
        // append the rest of the elements back into the chain
        if (idx1 == len1) { // then it was list2 (that was yet to be crawled), append it and that's all
            iter -> next = list2;
        } else { // it was list1, now since we do not want a loop, we'll smartly append the end of this sorted snippet with end of list2
            iter -> next = list1;
            while (idx1 != len1) {
                iter = iter -> next;
                idx1++;
            }
            iter->next = list2;
        }
        
        // iter = thead -> next;
        // cout << "\t\tafter sorting: ";
        // for (int i = 0; i < len1+len2; i++) {
        //     cout << iter->val << " ";
        //     iter = iter->next;
        // }
        // cout << endl;
        
        return thead->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) // a very stupid but important error/exception!
            return head;
        
        // initialize thead and temp lists
        ListNode *random_node = new ListNode(-100);
        
        int step = 1, count = 0, len1, len2;
        ListNode *temp = head, *node1, *node2, *endptr;
        while (temp != nullptr) {
            count++;
            temp = temp -> next;
        }
        // cout << "Count is: " << count << endl;
        
        bool first; // to detect if this is the first merging operation for a given step size
        while (step < count) {
            // cout << "Step size is: " << step << endl;
            temp = head;
            head = nullptr;
            for (int i = 0; i < count; i++) {
                if (i == 0)
                    first = true;
                else 
                    first = false;
                node1 = temp; len1 = step;
                // cout << "Node1 is: " << node1->val << endl;
                for (int j = 1; j < step; j++) {
                    if (temp == nullptr)
                        goto here;
                    temp = temp -> next; i++; 
                }
                
                if (temp == nullptr || temp->next == nullptr) // if there is no next element, then that means no list2 to merge with
                    break;
                temp = temp->next; i++;
                
                node2 = temp; len2 = 1;
                // cout << "Node2 is: " << node2->val << endl;
                for (int j = 1; j < step; j++) {
                    if (temp -> next == nullptr)
                        break;
                    temp = temp -> next; i++; len2++;
                }
                if (temp -> next != nullptr) // to look at the next item at the next merge step
                    temp = temp -> next;
                
                // when calling the merge function, reset 'iter' to random_node
                iter = random_node;
                iter->next = nullptr;
                
                if (first) {
                    head = merge(node1, node2, len1, len2);
                    endptr = head;
                    for (int j = 1; j < len1+len2; j++) 
                        endptr = endptr -> next;
                }
                else {
                    endptr -> next = merge(node1, node2, len1, len2);
                    for (int j = 0; j < len1+len2; j++) 
                        endptr = endptr -> next;
                }
            }
            here:
            step *= 2;
        }
        return head;
    }
};


// This solution is O(nlogn), but does require some extra space
/*
class Solution {
    ListNode* merge(ListNode* node1, ListNode* node2) {
        // cout << "\t\tGiven node1: " << node1->val << " node2: " << node2->val << endl;
        ListNode *head, *comb = nullptr;
        while (node1 != nullptr && node2 != nullptr) {
            if (node1 -> val < node2 -> val) {
                if (comb == nullptr) {
                    comb = node1;
                    head = comb;
                } else {
                    comb->next = node1;
                    comb = comb -> next;
                }
                node1 = node1 -> next;
            }
            else {
                if (comb == nullptr) {
                    comb = node2;
                    head = comb;
                } else {
                    comb->next = node2;
                    comb = comb -> next;
                }
                node2 = node2 -> next;
            }
        }
        if (node1 == nullptr)
            comb -> next = node2;
        else
            comb -> next = node1;
        
        // comb = head;
        // cout << "\t\tafter sorting: ";
        
        // while(comb != nullptr) {
        //     cout << comb->val << " ";
        //     comb = comb->next;
        // }
        // cout << endl;
        return head;
    }
    
    ListNode* sort(ListNode* head, int count) { // count is basically size of current list to be sorted
        if (count == 1) {
            return head;
        }
        
        int mid = count / 2;
        // cout << "Count: " << count << " mid: " << mid << endl;
        // to do the next steps, trim the list to just mid elements and following elements
        ListNode *node1, *node2, *list1, *list2;
        node1 = head;
        // cout << "\t node1: " << node1 -> val << endl;
        for (int i = 0; i < mid-1; i++)
            head = head -> next;
        
        node2 = head->next;
        // cout << "\t node2: " << node2 -> val << endl;
        head->next = nullptr; // to snip the first list
        // sort from 0 to mid
        list1 = sort(node1, mid);
        
        // sort from mid+1 to count
        list2 = sort(node2, count-mid);
        
        // now merge these sorted linked lists using merge
        return merge(list1, list2);
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return head;
        int count = 0;
        ListNode *temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp -> next;
        }
        return sort(head, count);
    }
};
*/

// A simple trivial O(nlogn) time and O(n) space solution
/*
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return head;
        vector<int> vec;
        while (head != nullptr) {
            vec.push_back(head -> val);
            head = head -> next;
        }
        
        sort(vec.begin(), vec.end());
        
        ListNode *temp = new ListNode(vec[0]);
        head = temp;
        for (int i = 1; i < vec.size(); i++) {
            temp -> next = new ListNode(vec[i]);
            temp = temp -> next;
        }
        return head;
    }
};
*/
