// Sol2 O(n) time, O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, h, dist;
        
        stack<int> stk;
        
        for (int i = 0; i < height.size(); i++) {
            while(!stk.empty() && height[i] > height[stk.top()]) {
                h = stk.top();
                stk.pop();
                if (stk.empty())
                    break;
                
                dist = i - stk.top() - 1;
                water += dist * (min(height[i], height[stk.top()]) - height[h]);
            }
            stk.push(i);
        }
        
        return water;
    }
};

// Sol1 O(n) time, O(1) space
/*
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;
        
        int prev_val = height[0], prev_idx = 0, n = height.size(), temp = 0, water = 0, i;
        for (i = 1; i < n; i++) {
            if (height[i] > prev_val) {
                prev_idx = i;
                prev_val = height[i];
                temp = 0;
            } else {
                water += prev_val - height[i];
                temp  += prev_val - height[i];;
            }
        }
        
        if (prev_idx != n-1) { // somewhere in middle we have the highest peak!
            water -= temp;
            prev_val = height[n-1];
            for (i = n-2; i > prev_idx; i--) {
                if (height[i] > prev_val) {
                    prev_val = height[i];
                } else {
                    water += prev_val - height[i];
                }
            }
        }
        
        return water;
    }
};
*/
