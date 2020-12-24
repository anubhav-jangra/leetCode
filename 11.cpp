class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_rect = 0;
        int start = 0, end = n - 1;
        
        while(start < end) {
            int current_area = (end - start) * min(height[start], height[end]);
            if(current_area > max_rect)
                max_rect = current_area;
            if(height[start] > height[end])
                end--;
            else
                start++;
        }
        
        return max_rect;
        
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(abs(i - j) * min(height[i], height[j]) > max_rect)
        //             max_rect = abs(i - j) * min(height[i], height[j]);
        //     }
        // }
        // return max_rect;
    }
};
