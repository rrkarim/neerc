class Solution {
public: 
    int hor_used[10], ver_used[10], diag1_us[20], diag2_us[20];
    int us[10][10];
    int res = 0;
    vector <vector<string> > v;
    vector<string> temp;
    void f(int k, const int &n) {
        if(k == n) {
            v.push_back(temp), res += 1;
            return;
        }
        int vi[90], vi2[90], len = 0;
        for(int j = 0; j < n; ++j) {
            if(us[k][j] || ver_used[j]) continue;
            int diag = (n - k - 1) + j, x = k + j;
            if(!hor_used[k] && !ver_used[j] && !diag1_us[x] && !diag2_us[diag]) {
                    hor_used[k] = 1, ver_used[j] = 1;
                    diag1_us[x] = 1, diag2_us[diag] = 1;
                    temp[k][j] = 'Q';
                    f(k + 1, n);
                    temp[k][j] = '.';
                    us[k][j] = 1;
                    vi[len] = k, vi2[len] = j;
                    len += 1;
                    hor_used[k] = 0, ver_used[j] = 0;
                    diag1_us[x] = 0, diag2_us[diag] = 0;
                }
            }
            for(int i = 0; i < len; ++i) us[vi[i]][vi2[i]] = 0;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <vector<string>> ret;
        temp.resize(n);
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) temp[i] += '.';
        f(0, n);
        return v;
    }
};