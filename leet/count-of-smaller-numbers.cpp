class Solution {
public:
    int t[400000], used[100000];
    void build (int v, int tl, int tr) {
    	if (tl == tr)
    		t[v] = 1;
    	else {
    		int tm = (tl + tr) / 2;
    		build (v*2, tl, tm);
    		build (v*2+1, tm+1, tr);
    		t[v] = t[v*2] + t[v*2+1];
    	}
    }
    int sum (int v, int tl, int tr, int l, int r) {
    	if (l > r)
    		return 0;
    	if (l == tl && r == tr)
    		return t[v];
    	int tm = (tl + tr) / 2;
    	return sum (v*2, tl, tm, l, min(r,tm))
    		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
    }
    void update (int v, int tl, int tr, int pos, int new_val) {
    	if (tl == tr)
    		t[v] = new_val;
    	else {
    		int tm = (tl + tr) / 2;
    		if (pos <= tm)
    			update (v*2, tl, tm, pos, new_val);
    		else
    			update (v*2+1, tm+1, tr, pos, new_val);
    		t[v] = t[v*2] + t[v*2+1];
    	}
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector <int> r;
        if(nums.size() == 1) return {0};
        if(nums.size() == 0) return r;
        vector <int> st;
        vector <int>::iterator it;
        int n = nums.size(), s = 0;
        build(1, 0, n - 2);
        fill(used, used + n, 0);
        for(int i = 1; i < n; ++i) {
            if(nums[0] - nums[i] > 0) s += 1;
            st.push_back(nums[0] - nums[i]);
        }
        sort(st.begin(), st.end());
        r.push_back(s);
        for(int i = 1; i < n - 1; ++i) {
            it = lower_bound(st.begin(), st.end(), nums[0] - nums[i]);
            int index = it - st.begin();
            while(used[index]) index += 1;
            update(1, 0, n - 2, index, 0);
            used[index] |= 1;
            it = lower_bound(st.begin(), st.end(), nums[0] - nums[i] + 1);
            r.push_back(sum(1, 0, n - 2, it - st.begin(), n - 2));
        }
        r.push_back(0);
        return r;
    }
};