bool compareFunc(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

class Solution {
    void sort_map(map<char, int> &freq, vector<pair<char, int>> &vec) {
        map<char, int>::iterator itr;
        for (itr = freq.begin(); itr != freq.end(); ++itr)
            vec.push_back(pair<char, int>(itr->first, itr->second));
        sort(vec.begin(), vec.end(), compareFunc);
    }
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }
        
        vector<pair<char, int>> vec;
        sort_map(freq, vec);
        string ans = "";
        for (int i = 0; i < vec.size(); i++)
            for (int j = 0; j < vec[i].second; j++)
                ans += vec[i].first;
        return ans;
    }
};

// Sol 2
/*
bool compareFunc(string &a, string &b) {
    return a.length() > b.length();
}

class Solution {
public:
    string frequencySort(string s) {
        vector<char> vec;
        for (int i = 0; i < s.length(); i++) {
            vec.push_back(s[i]);
        }

        sort(vec.begin(), vec.end());
        
        string temp;
        vector<string> vec2;
        for (int i = 0; i < vec.size(); i++) {
            temp = "";
            temp += vec[i];
            for (int j = i+1; ; j++) {
                if (j == vec.size()) {
                    i = vec.size();
                    break;
                }
                if (vec[j] == vec[i]) {
                    temp += vec[j];
                } else {
                    i = j-1;
                    break;
                }
            }
            vec2.push_back(temp);
        }
        
        sort(vec2.begin(), vec2.end(), compareFunc);
        string ans = "";
        for (int i = 0; i < vec2.size(); i++)
                ans += vec2[i];
        return ans;
    }
};
*/

// Sol 1
/*
bool compareFunc(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

class Solution {
    void sort_map(map<char, int> &freq, vector<pair<char, int>> &vec) {
        map<char, int>::iterator itr;
        for (itr = freq.begin(); itr != freq.end(); ++itr)
            vec.push_back(pair<char, int>(itr->first, itr->second));
        sort(vec.begin(), vec.end(), compareFunc);
    }
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (int i = 0; i < s.length(); i++) {
            map<char, int>::iterator itr = freq.find(s[i]);
            if (itr == freq.end()) // new element found
                freq.insert(pair<char, int>(s[i], 1));
            else
                itr->second++;
        }
        
        vector<pair<char, int>> vec;
        sort_map(freq, vec);
        string ans = "";
        for (int i = 0; i < vec.size(); i++)
            for (int j = 0; j < vec[i].second; j++)
                ans += vec[i].first;
        return ans;
    }
};
*/
