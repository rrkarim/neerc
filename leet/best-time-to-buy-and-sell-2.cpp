/**
    Best Time to Buy and Sell Stock II
    Simple Greedy solution
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0; if(prices.size() == 0) return res;
        int x = prices[0], pre = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > pre) {
                pre = prices[i];
                continue;
            }
            else {
                if(pre != -1) {
                    res += pre - x;
                }
                x = prices[i];
            }
            pre = prices[i];
        }   
        if(pre != -1 && pre - x > 0) res += pre - x;
        return res;
    }
};