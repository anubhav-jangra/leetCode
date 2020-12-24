class Solution {
    int target_, mid;
    int binarySearch(vector<int> &nums, int l, int r) {
        if (l > r)
            return -1;
        mid = l + (r - l)/2;
        
        if (nums[mid] == target_)
            return mid;
        else if (nums[mid] >= nums[l]) { // left side is sorted
            if (nums[mid] > target_ && target_ >= nums[l])
                return binarySearch(nums, l, mid-1);
            return binarySearch(nums, mid+1, r);
        } else { // right side sorted
            if (nums[mid] < target_ && target_ <= nums[r])
                return binarySearch(nums, mid+1, r);
            return binarySearch(nums, l, mid-1);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        target_ = target;
        return binarySearch(nums, 0, nums.size()-1);
    }
};

/*
class Solution {
    int pivot, mid, target_, start;
    bool cond(vector<int> &nums, int i) {
        if (i != 0 && i != nums.size())
            if (nums[i-1] < nums[i] && nums[i] > nums[i+1])
                return true;
        return false;
    }
    void find_pivot(vector<int> &nums, int l, int r) {
        if (l > r || pivot != -1)
            return;
        mid = l + (r - l)/2;
        // cout << "l: " << l << " r: " << r << " mid: " << mid << endl;
        if (cond(nums, mid)) {
            pivot = mid;
            return;
        }
        if (nums[mid] >= start)
            find_pivot(nums, mid+1, r);
        else
            find_pivot(nums, l, mid-1);
    }
    
    int binarySearch(vector<int> &nums, int l, int r) {
        if (l > r)
            return -1;
        mid = l + (r - l)/2;
        if (nums[mid] == target_)
            return mid;
        
        if (nums[mid] > target_)
            return binarySearch(nums, l, mid-1);
        return binarySearch(nums, mid+1, r);
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            return -1;
        }
        if (nums.size() == 2) {
            if (nums[0] == target)
                return 0;
            else if (nums[1] == target)
                return 1;
            return -1;
        }
        target_ = target;
        start = nums[0];
        pivot = -1;
        // detect the pivot in O(logn)
        if (nums[0] > nums[1]) // pivot is 1st element
            pivot = 0;
        else if (nums[0] < nums[nums.size()-1]) // already sorted array, i.e. pivot is the last element (against the statement 'the array is guarenteed to be rotated'!!)
            pivot = nums.size()-1;
        else
            find_pivot(nums, 0, nums.size()-1);
        
        // cout << "Pivot is: " << pivot << endl;
        
        // now run binary searches in individual parts of the array
        
        int idx_l = binarySearch(nums, 0, pivot);
        int idx_r = binarySearch(nums, pivot+1, nums.size()-1);
        if (idx_l == -1)
            return idx_r;
        else 
            return idx_l;
    }
};*/
