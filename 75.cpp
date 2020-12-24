class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                red += 1;
            else if (nums[i] == 1)
                white += 1;
            else 
                blue += 1;
        }
        // cout << "Red: " << red << " White: " << white << " Blue: " << blue << endl;
        for (int i = 0; i < red; i++)
            nums[i] = 0;
        for (int i = red; i < red + white; i++)
            nums[i] = 1;
        for (int i = red + white; i < red + white + blue; i++)
            nums[i] = 2;
    }
};
