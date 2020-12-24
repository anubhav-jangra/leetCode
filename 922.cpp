#include <bits/stdc++.h>

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        for (int i = 0; i < A.size(); i++) {
            if ((i % 2 == 0 && A[i] % 2 == 0) || (i % 2 == 1 && A[i] % 2 == 1))
                continue;

            for (int j = i + 1; j < A.size(); j++) {
                if ((j % 2 == 0 && A[j] % 2 == 0) || (j % 2 == 1 && A[j] % 2 == 1))
                    continue;
                
                if (A[j] % 2 != A[i] % 2) {
                    swap(A[i], A[j]);
                    break;
                }
            }
        }

        return A;
    }
};
