class MyLinkedList {
    int val;
    MyLinkedList *next = nullptr;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        val = -100;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // cout << "GET operation: " << index << endl;
        index++;
        MyLinkedList *temp = this;
        while (index > 0 && temp) {
            temp = temp -> next;
            index--;
        }
        if (!temp) {
            // cout << "Returning -1\n";
            return -1;
        }
        // cout << "Returning " << temp->val << endl;
        return temp -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        // cout << "ADD_AT_HEAD operation: " << val << endl;
        
        MyLinkedList *temp = new MyLinkedList(), *temp2 = this;
        temp -> val = val;
        temp -> next = temp2 -> next;
        temp2 -> next = temp;
        
        // MyLinkedList *rough = this;
        // while(rough) {
        //     cout << rough -> val << " ";
        //     rough = rough -> next;
        // }
        // cout << endl;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        // cout << "ADD_AT_TAIL operation: " << val << endl;
        
        MyLinkedList *temp = this;
        while (temp -> next) {
            temp = temp -> next;
        }
        MyLinkedList *temp2 = new MyLinkedList();
        temp2 -> val = val;
        temp -> next = temp2;
        
        // MyLinkedList *rough = this;
        // while(rough) {
        //     cout << rough -> val << " ";
        //     rough = rough -> next;
        // }
        // cout << endl;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        // cout << "ADD_AT_INDEX operation: " << index << " " << val << endl;

        MyLinkedList *temp = this;
        for (int i = 0; i < index; i++) {
            if (!temp -> next) {
                addAtTail(val);
            }
            temp = temp->next;
        }
        MyLinkedList *temp2 = new MyLinkedList();
        temp2 -> val = val;
        temp2 -> next = temp -> next;
        temp -> next = temp2;
        
        // MyLinkedList *rough = this;
        // while(rough) {
        //     cout << rough -> val << " ";
        //     rough = rough -> next;
        // }
        // cout << endl;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // cout << "DELETE_AT_INDEX operation: " << index << endl;
        
        MyLinkedList *temp = this;
        for (int i = 0; i < index; i++) {
            if (! (temp -> next))
                return;
            temp = temp->next;
        }
        if (temp -> next) {
            MyLinkedList *temp2 = temp -> next;
            temp -> next = temp -> next -> next;
            delete temp2;
        }
        
        // MyLinkedList *rough = this;
        // while(rough) {
        //     cout << rough -> val << " ";
        //     rough = rough -> next;
        // }
        // cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
