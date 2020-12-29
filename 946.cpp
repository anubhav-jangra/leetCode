class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0) // handle edge case
            return true;
        
        int ptr1 = 0, ptr2 = 0;
        vector<int> stk;
        stk.push_back(pushed[ptr1++]); // so that the stack is non-emnpty
        
        while (ptr2 < pushed.size()) {
            if (stk.size() && stk.back() == popped[ptr2]) { // check if something can be correctly popped at the moment
                ptr2++;
                stk.pop_back();
            } else if (ptr1 < pushed.size()){ // push the new element into the stack
                    stk.push_back(pushed[ptr1++]);
            } else {
                return false;
            }
        }
        
        return true;
    }
};
