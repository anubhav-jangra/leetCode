// Successful attempt Style-3 (more optimized)
class FreqStack {
    int max_freq = 0;
    unordered_map<int, int> freq; // mapping from an element to its frequency
    unordered_map<int, vector<int>> freq_stk; // maps each frequency to the stack containing ordering
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        // cout << "To push " << x << endl;
        freq[x]++;
        if (freq[x] > max_freq) 
            max_freq = freq[x];
        
        freq_stk[freq[x]].push_back(x);
        // printStk();
    }
    
    int pop() {
        int ans = freq_stk[max_freq].back();
        freq[ans]--;
        freq_stk[max_freq].pop_back();
        // check if there are anymore elements in that frequency, else decrease the value to next smallest frequency
        if (freq_stk[max_freq].empty())
            freq_stk.erase(max_freq--);
        return ans;
    }
};


// Successful attempt Style-2
/*
class FreqStack {
    int max_freq = 0;
    map<int, int> freq; // mapping from an element to its frequency
    map<int, vector<int>> freq_stk; // maps each frequency to the stack containing ordering
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        // cout << "To push " << x << endl;
        freq[x]++;
        if (freq[x] > max_freq) 
            max_freq = freq[x];
        
        freq_stk[freq[x]].push_back(x);
        // printStk();
    }
    
    int pop() {
        int ans = freq_stk[max_freq].back();
        freq[ans]--;
        freq_stk[max_freq].pop_back();
        // check if there are anymore elements in that frequency, else decrease the value to next smallest frequency
        if (freq_stk[max_freq].empty())
            freq_stk.erase(max_freq--);
        return ans;
    }
};
*/

// after catching a glimpse of the solution 
// Successful attempt (Style 1)
/*
class FreqStack {
    int max_freq = 0;
    map<int, int> freq; // mapping from an element to its frequency
    map<int, vector<int>> freq_stk; // maps each frequency to the stack containing ordering
public:
    FreqStack() {
        
    }
    
    // a handy code for debugging
    void printStk() {
        cout << "Freq Stack is: \n";
        for (auto iter = freq_stk.begin(); iter != freq_stk.end(); iter++) {
            cout << "\t" << iter -> first << " / ";
            for (int i = 0; i < iter->second.size(); i++) 
                cout << iter -> second[i] << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    void push(int x) {
        // cout << "To push " << x << endl;
        auto iter = freq.find(x);
        int curr_freq;
        if (iter == freq.end()) {
            freq.insert({x, 1});
            curr_freq = 1;
        } else {
            iter -> second++;
            curr_freq = iter -> second;
        }
        
        if (curr_freq > max_freq) 
            max_freq = curr_freq;
        
        auto iter2 = freq_stk.find(curr_freq);
        if (iter2 != freq_stk.end()) {
            iter2 -> second.push_back(x);
        } else {
            freq_stk.insert(pair<int, vector<int>>(curr_freq, vector<int>{x}) );
        }
        // printStk();
    }
    
    int pop() {
        auto iter = freq_stk.find(max_freq);
        int ans = iter -> second.back();
        auto iter2 = freq.find(ans);
        iter2 -> second--;
        iter -> second.pop_back();
        // check if there are anymore elements in that frequency, else decrease the value to next smallest frequency
        if (iter -> second.empty())
            freq_stk.erase(max_freq--);
        
        // cout << "POPPING " << ans << endl;
        // printStk();
        return ans;
    }
};
*/
    
// Failed attempt 3
/*
class FreqStack {
    vector<int> stk, temp_stk;
    map<int, int> freq;
public:
    FreqStack() {
        
    }
    
    void printStk() {
        cout << "Stack is: ";
        for (int i = 0; i < stk.size(); i++) 
            cout << "<" << stk[i] << ", " << freq[stk[i]] << "> ";
        cout << endl;
    }
    
    void push(int x) {
        cout << "To push " << x << endl;
        auto iter = freq.find(x);
        if (iter == freq.end()) {
            freq.insert({x, 1});
        } else {
            iter -> second++;
        }
        stk.push_back(x);
        printStk();
    }
    
    int pop() {
        
        auto max_pr = max_element (freq.begin(), freq.end(), 
                [] (const pair<int, int> &p1, const pair<int, int> &p2) {
                return p1.second < p2.second;
                }
        );
        
        int max_idx;
        for (int i = stk.size() - 1; i >= 0; i--) {
            if (stk[i] == max_pr->first) {
                max_idx = i;
                break;
            }
        }
        
        // also decrease the frequency by one
        max_pr -> second--;
        
        // now remove the max_idx_th element
        for (int i = stk.size()-1; i >= max_idx; i--) {
            temp_stk.push_back(stk.back());
            stk.pop_back();
        }
        // removing the max_idx_th element from the temp_stk
        temp_stk.pop_back();
        
        while (!temp_stk.empty()) {
            stk.push_back(temp_stk.back());
            temp_stk.pop_back();
        }
        
        cout << "POPPING " << max_pr -> first << endl;
        printStk();
        return max_pr -> first;
    }
};
*/

// Failed attempt 2
/* 
class FreqStack {
    vector<int> stk, temp_stk;
    map<int, int> freq;
public:
    FreqStack() {
        
    }
    
    void printStk() {
        cout << "Stack is: ";
        for (int i = 0; i < stk.size(); i++) 
            cout << "<" << stk[i] << ", " << freq[stk[i]] << "> ";
        cout << endl;
    }
    
    void push(int x) {
        // cout << "To push " << x << endl;
        auto iter = freq.find(x);
        if (iter == freq.end()) {
            freq.insert({x, 1});
        } else {
            iter -> second++;
        }
        stk.push_back(x);
        // printStk();
    }
    
    int pop() {
        // find the item with maximum frequency by screening over the entire stack
        int max_freq = freq[stk[stk.size()-1]], max_idx = stk.size()-1, ans;
        for (int i = stk.size() - 2; i >= 0; i--) {
            if (stk[i] != stk[max_idx] && freq[stk[i]] > max_freq) {
                max_idx = i;
                max_freq = freq[stk[i]];
            }
        }
        // save the answer, since removing it from stack
        ans = stk[max_idx];
        
        // also decrease the frequency by one
        auto iter = freq.find(ans);
        iter -> second--;
        
        // now remove the max_idx_th element
        for (int i = stk.size()-1; i >= max_idx; i--) {
            temp_stk.push_back(stk.back());
            stk.pop_back();
        }
        // removing the max_idx_th element from the temp_stk
        temp_stk.pop_back();
        
        while (!temp_stk.empty()) {
            stk.push_back(temp_stk.back());
            temp_stk.pop_back();
        }
        
        // cout << "POPPING " << ans << endl;
        // printStk();
        return ans;
    }
};
*/

// Failed attempt-1
/*
class FreqStack {
    priority_queue<pair<int, int>> stk, stk2;
    pair<int, int> temp;
    bool flg;
public:
    FreqStack() {
        
    }
    
    void printStk() {
        stk2 = stk;
        cout << "Current stack is: ";
        while (!stk2.empty()) {
            temp = stk2.top();
            stk2.pop();
            cout << "<" << temp.first << ", " << temp.second << "> ";
        }
        cout << endl;
    }
    
    void push(int x) {
        cout << "To push " << x << endl;
        flg = false;
        // check if element is present in the queue already (for that we have another array for simplicity)
        while (!stk.empty()) {
            temp = stk.top();
            if (temp.second == x) { // element found
                flg = true;
                stk.pop();
                temp.first++;
                stk.push(temp);
                break;
            }
            stk.pop();
            stk2.push(temp);
        }
        if (!flg) { // new element
            temp = pair<int, int>(1, x);
            stk.push(temp);
        }
        // now re-enter the items into stk from stk2
        while (!stk2.empty()) {
            stk.push(stk2.top()); stk2.pop();
        }
        printStk();
    }
    
    int pop() {
        temp = stk.top();
        // this is the element which was added the first, but we seek the most recently added element, hence 
        
        cout << "POPPING " << temp.second << endl;
        stk.pop();
        temp.first--;
        if (temp.first >= 1)
            stk.push(temp);
        printStk();
        return temp.second;
    }
};
*/
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

// For pushing functionality:
// Hash Maps are a nice idea, however sorting them would be an issue!

// For pop functionality: O(logn) solutions:
// Heap -> O(n) search
// Priority Queue (same as heap ;) )

// We'll go with heap for now.

// But maybe we can also use pointers, heaps and hashmaps?
