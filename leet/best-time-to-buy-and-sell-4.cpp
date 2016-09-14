/*
	Best Time to Buy and Sell Stock IV
	O(n*n*k) vs O(n*k)
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0 || n <= 1) return 0;
        if(k >= n - 1) {
            int res = 0, x = prices[0];
            for(int i = 1; i < n; ++i) {
                if(prices[i] < x) x = prices[i];
                else {
                    res += prices[i] - x;
                    x = prices[i];
                }
            }
            return res;
        }
        k = min(k, n/2);
        int l[2][n+1]; memset(l,0,sizeof l);
        queue <int> q;
        q.push(prices[0]); l[1][0] = 0;
        int res = 0, ans = 0;
        for(int i = 1; i < n; ++i) {
            while(!q.empty()) {
                if(prices[i] > q.front()) break;
                q.pop();
            }
            if(q.empty()) q.push(prices[i]);
            else res = max(res, prices[i] - q.front());
            l[0][i] = res;
        }
        
        for(int z = 2; z <= k; ++z) {
            
            for(int i = (z*2-1);i < n; ++i) {
                int res = 0;
                for(int j = i-1; j >= 0; --j) {
                    res = max(res, prices[i]-prices[j] + (j == 0 ? 0 : l[0][j-1]));
                }
                l[1][i] = max(l[1][i-1], res);
            }
            for(int i = 0; i < n; ++i) l[0][i] = max(l[0][i], l[1][i]);
        }
        int maxn = 0;
        for(int i = 0; i < n; ++i) maxn = max(maxn, l[0][i]);
        return maxn;
    }
};