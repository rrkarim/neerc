/**
    Best Time to Buy and Sell Stock II && I
    Simple Greedy solution/Linear
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
/*** */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        queue <int> q;
        q.push(prices[0]);
        int res = 0;
        for(int i = 1; i < prices.size(); ++i) {
            while(!q.empty()) {
                if(prices[i] > q.front()) break;
                q.pop();
            }
            if(q.empty()) q.push(prices[i]);
            else {
                res = max(res, prices[i] - q.front());
            }
        }
        return res;
    }
};