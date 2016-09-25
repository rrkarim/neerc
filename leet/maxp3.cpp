typedef long long ll;
int Solution::maxp3(vector<int> &A) {
    if(A.size() < 3) {
        int res = 1;
        for(int i = 0; i < A.size(); ++i) res *= A[i];
        return res;
    }
    ll dp_minn[4][A.size() + 2];
    ll dp_maxn[4][A.size() + 2];
    dp_minn[1][0] = dp_maxn[1][0] = A[0];
    for(int i = 1; i < A.size(); ++i) {
        dp_minn[1][i] = min(dp_minn[1][i - 1], 1ll*A[i]);
        dp_maxn[1][i] = max(dp_maxn[1][i - 1], 1ll*A[i]);
    }
    dp_minn[2][1] = dp_maxn[2][1] = A[0]*A[1]; 
    for(int i = 2; i < A.size(); ++i) {
        if(A[i] > 0) {
            dp_minn[2][i] = min(dp_minn[2][i - 1], A[i] * dp_minn[1][i-1]);
            dp_maxn[2][i] = max(dp_maxn[2][i - 1], A[i] * dp_maxn[1][i-1]);
        }   
        else {
            dp_minn[2][i] = min(dp_minn[2][i - 1], A[i] * dp_maxn[1][i-1]);
            dp_maxn[2][i] = max(dp_maxn[2][i - 1], A[i] * dp_minn[1][i-1]);
        }
    }
    dp_minn[3][2] = dp_maxn[3][2] = A[0]*A[1]*A[2];
    for(int i = 3; i < A.size(); ++i) {
        if(A[i] > 0) {
            dp_minn[3][i] = min(dp_minn[3][i - 1], A[i] * dp_minn[2][i-1]);
            dp_maxn[3][i] = max(dp_maxn[3][i - 1], A[i] * dp_maxn[2][i-1]);
        }
        else {
            dp_minn[3][i] = min(dp_minn[3][i - 1], A[i] * dp_maxn[2][i-1]);
            dp_maxn[3][i] = max(dp_maxn[3][i - 1], A[i] * dp_minn[2][i-1]);
        }
    }
    return dp_maxn[3][A.size()-1];
}
