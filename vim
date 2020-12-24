// since we need a stable sort for this problem!
bool comp_(const pair<int, int> &pr1, const pair<int, int> &pr2) {
    if (pr1.second == pr2.second) 
        return (pr1.first < pr2.first);
    return (pr1.second < pr2.second);
}

class Solution {
public:
    
    int power_(int x) {
        int ans = 0;
        while(x != 1) {
            if (x % 2 == 0) // even
                x = x / 2;
            else
                x = 3 * x + 1;
            ans++;
        }
        return ans;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair <int, int> > arr;
        for (int i = lo; i <= hi; i++) {
            pair<int, int> pr(i, power_(i));
            arr.push_back(pr);
        }
        
        // sort arr on the basis of second element
        sort(arr.begin(), arr.end(), comp_);
        
        return arr[k-1].first;
    }
};
