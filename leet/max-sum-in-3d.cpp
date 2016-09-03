/**
    Max Sum of Rectangle No Larger Than K
*/
class Solution {
public:
    int sum_ar(vector<int>& d, int k) {
        set <int> st;
        st.insert(0);
        int sum = 0, maxn = -1000000;
        for(int i = 0; i < d.size(); ++i) {
            sum += d[i];
            set <int>::iteartor it = st.lower_bound(sum - k);
            if(it !=  st.end()) maxn = max(maxn, sum - *it);
            st.insert(sum);
        }
        return maxn;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); if(n == 0) return 0;
        int m = matrix[0].size(), res = -10000000;
        for(int i = 0; i < m; ++i) {
            vector <int> rw_sums(n, 0);
            for(int j = i; j < m; ++j) {
                for(int z = 0; z < n; ++z) {
                    rw_sums[z] += matrix[z][j];
                }
                int sum = sum_ar(rw_sums, k);
                if(sum > res && sum <= k) {
                    res = sum;
                }
            }
        }
        return res;
    }
};