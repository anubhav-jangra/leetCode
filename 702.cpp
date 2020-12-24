/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
    int oob = 2147483647;
public:
    int search(const ArrayReader& reader, int target) {
        // implement a binary search:
        int l = 0, r = target - reader.get(0), mid, val;
        while (true) {
            if (l > r)
                return -1;
            mid = l + (r - l) / 2;
            val = reader.get(mid);
            // cout << "L is: " << l << " R is: " << r << " Mid is:" << mid << endl;
            if (val == target) 
                return mid;
            else if (val > target)
                r = mid-1;
            else
                l = mid+1;
        }
    }
};
