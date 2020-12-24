#include <bits/stdc++.h>

class Solution {
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    int maxPos(vector<int>& arr, int last_val) {
        int ans = 0;
        for (int i = 1; i < last_val; i++) {
            if (arr[ans] < arr[i])
                ans = i;
        }
        return ans+1; // since the rest of the system works with first index '1' type system
    }
    
    void flip(vector<int>& arr, int k) {
        cout << "flliping for k = " << k << endl;
        for(int i = 0; i < k; i++) {
            if (i == k-i-1 || i > k-i-1)
                break;
            swap(&arr[i], &arr[k-i-1]);
        }
    }
    
    void print_arr(const vector<int>& arr) {
        cout << "Printing array: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    bool isSorted(const vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i+1]) 
                return false;
        }
        return true;
    }
    
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> poses;
        print_arr(arr);
        
        for (int i = 0; i < arr.size()-1 && !isSorted(arr); i++) {
            int max_pos = maxPos(arr, arr.size() - i);
            if (max_pos != 1) {
                flip(arr, max_pos);
                poses.push_back(max_pos);
            }
            print_arr(arr);
            // now the largest element is in the first position
            // hence flip arr.size() - i
            flip(arr, arr.size() - i);
            poses.push_back(arr.size() - i);
            print_arr(arr);
        }
        
        return poses;
    }
};
