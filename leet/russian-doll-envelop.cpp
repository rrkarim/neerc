class Solution {
public:
    int INF = 10000000;
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        vector <int> a;
        int n = envelopes.size();
        if(n == 0) return 0;
        
        for(int i = 0; i < envelopes.size(); ++i) a.push_back(envelopes[i].second);
        
        vector <int> d(n + 2, 0);
        for (int i=0; i<n; ++i) {
        	d[i] = 1;
        	for (int j=0; j<i; ++j)
        		if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
        			d[i] = max (d[i], 1 + d[j]);
        }
        int res = 1;
        for(int i = 0; i < n; ++i) res = max(res, d[i]);
        return res;
        
    }
};