class Solution {
    void print_arr(const vector<int>& arr) {
        cout << "Printing array: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 0)
            return;
        bool rough;
        // while(true) {
            for (int i = 0; i < nums.size()-1; i++) {
                rough = false;
                if ((i%2 == 0 && nums[i] > nums[i+1]) || (i%2 == 1 && nums[i] < nums[i+1])) {
                        swap(&nums[i], &nums[i+1]);
                        // rough == true;
                }
            }
            // if (!rough)
                // break;
        // }
    }
    
    // sol-1
    /*
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 0)
            return;
        sort(nums.begin(), nums.end());
        // print_arr(nums);
        for (int i = 1; i < nums.size()-1; i=i+2) {
            swap(&nums[i], &nums[i+1]);
        }
    }
    */
    
    // failed solution
    /*
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        sort(nums.begin(), nums.end());
        // print_arr(nums);
        int temp, k = nums.size() / 2; // experiment with this as well
        for (int i = 0; i < k; i=i+2) {
            // insert i+n/2 at ith location and move others
            temp = nums[i/2+k];
            for (int j = i/2+k-1; j > i; j--) {
                nums[j+1] = nums[j];
            }
            nums[i+1] = temp;
            // print_arr(nums);
        }
        if (nums.size() % 2) 
            swap(&nums[nums.size()-1], &nums[nums.size()-2]);
    }*/
};
