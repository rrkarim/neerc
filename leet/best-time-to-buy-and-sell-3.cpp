/**
    Best Time to Buy and Sell Stock III
    Store left and right maximums
*/
class Solution {
public:
    int minn = -1000000;
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;        
        vector <int> l(n), r(n);
        queue <int> q, q1;
        q.push(prices[0]); l[0] = 0;
        int res = 0, ans = 0;
        for(int i = 1; i < n; ++i) {
            while(!q.empty()) {
                if(prices[i] > q.front()) break;
                q.pop();
            }
            if(q.empty()) q.push(prices[i]);
            else res = max(res, prices[i] - q.front());
            l[i] = res;
        }
        reverse(prices.begin(), prices.end());
        res = 0;
        q1.push(prices[0]); r[0] = 0;
        for(int i = 1; i < n; ++i) {
            while(!q1.empty()) {
                if(prices[i] < q1.front()) break;
                q1.pop();
            }
            if(q1.empty()) q1.push(prices[i]);
            else res = max(res, q1.front() - prices[i]);
            r[i] = res;
        }
        reverse(r.begin(), r.end());
        for(int i = 0; i < n; ++i) { 
            if(i == n - 1) ans = max(ans, l[i]);
            else ans = max(ans, l[i] + r[i + 1]);
        }
        return ans;
    }
};