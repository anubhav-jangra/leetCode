#define NIL numeric_limits<int>::min()
class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     if(prices.size() <= 1) 
    //         return 0;
    //     vector<pair<int, int> > dp_table;
    //     dp_table.push_back(make_pair(0, NIL));
    //     for(int i = 1; i < prices.size(); i++) {
    //         cout << "i is -> " << i << endl;
    //         int max_index, min_index;
    //         if(prices[i] < prices[i-1] && dp_table.back().second == NIL) {
    //             max_index = NIL;
    //         } else {
    //             if(i > dp_table.back().first) {
    //                 max_index = max(prices[dp_table.back().second], prices[i]) == prices[i] ? i : dp_table.back().second;
    //             } else {
    //                 max_index = dp_table.back().first;
    //             }
    //         }
    //         if(i < dp_table.back().second) {
    //             min_index = min(prices[dp_table.back().first], prices[i]) == prices[i] ?  : dp_table.back().first;
    //         } else {
    //             min_index = dp_table.back().second;
    //         }
    //         dp_table.push_back( make_pair( min_index, max_index ) );
    //     }
    //     for(int i = 0; i < prices.size(); i++) {
    //         cout << dp_table[i].first << " " << dp_table[i].second << endl;
    //     }
    //     if(dp_table.back().second == NIL) {
    //         return 0;
    //     }
    //     return (prices[dp_table.back().second] - prices[dp_table.back().first]);
    // }
    int maxProfit(vector<int>& prices) {
        int minprice = numeric_limits<int>::max();
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
};
