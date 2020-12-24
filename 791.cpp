class Solution {
    void swap(char *a, char *b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
public:
    string customSortString(string S, string T) {
        int counter = 0;
        for (int i = 0; i < S.length(); i++) {
            for (int j = i; j < T.length(); j++) {
                if (T[j] == S[i]) {
                    swap(&T[j], &T[counter++]);
                }
            }
        }
        return T;
    }
};
