#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[505][505];
int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int c = -1, r = -1;
    for(int i=0;i<n;++i) {
        for(int j =  0; j < n; ++j) {
            cin  >>  A [i] [j];
            if(A[i][j] == 0) {
                r = i;
                c = j;
            }
        }
    }
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll sum = -1;
    for(int i = 0; i < n; ++i) {
        if(i == r) continue;
        ll temp_sum = 0;
        for(int j = 0; j < n; ++j) temp_sum += A[i][j];
        if(sum == -1) sum = temp_sum;
        else {
            if(temp_sum != sum) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(i == c) continue;
        ll temp_sum = 0;
        for(int j = 0; j < n; ++j) temp_sum += A[j][i];
        if(temp_sum != sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll sum_ = 0, x = 0, x2 = 0;
    for(int i = 0; i < n; ++i) {
        sum_ += A[r][i];
    }
    x = sum - sum_;
    if(x <= 0) {
        cout << "-1" << endl;
        return 0;
    }
    sum_ = 0;
    for(int i = 0; i < n; ++i) {
        sum_ += A[i][c];
    }
    x2 = sum - sum_;
    if(x2 <= 0) {
        cout << "-1" << endl;
        return 0;
    }
    if(x2 != x) {
        cout << "-1" << endl;
        return 0;
    }
    A[r][c] = x2;
    ll tt = 0, ss = 0;
    for(int i = 0; i < n; ++i) {
        tt += A[i][i];
    }
    if(tt != sum) {
        cout << "-1" << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        ss += A[i][n - i - 1];
    }
    if(ss != sum) {
       cout << "-1" << endl;
        return 0;
    }
    cout << x << endl;

}