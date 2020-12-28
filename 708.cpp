/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // check if list is null
        if (!head) {
            Node *temp = new Node(insertVal);
            temp -> next = temp;
            return temp;
        }
        // check is list is of size 1
        if (head == head -> next) {
            head -> next = new Node(insertVal);
            head -> next -> next = head;
            return head;
        }
        Node *temp = head;
        // first find the largest element
        while (temp -> val <= temp -> next -> val) {
            temp = temp -> next;
            if (temp == head)
                break;
        }
        
        cout << "largest value is: " << temp -> val << endl;
        cout << "smallest value is: " << temp -> next -> val << endl;
        
        // find the place where the target should be inserted
        if (insertVal < temp -> val && insertVal > temp -> next -> val) {
            temp = temp -> next;
            while (true) {
                if (temp -> val <= insertVal && temp -> next -> val > insertVal)
                    break;
                temp = temp -> next;
            }
        }
        cout << "Break point is: " << temp -> val << endl;
        // insert a new node
        Node *temp2 = temp -> next;
        temp -> next = new Node(insertVal);
        temp -> next -> next = temp2;
        return head;
    }
};
