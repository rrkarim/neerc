#include <bits/stdc++.h>
#define MAXIMUS 100005
#define INFF 1000000000000000

using namespace std;

typedef long long ll;

ll a[MAXIMUS + 2];
string s[MAXIMUS + 2], s1[MAXIMUS + 2];
ll DP1[MAXIMUS + 2], DP2[MAXIMUS + 2];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {
            cin>>a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        string t = s[i];
        reverse(s[i].begin(), s[i].end());
        s1[i] = s[i];
        s[i] = t;
    }
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            DP1[i] = 0;
            DP2[i] = a[i];
        }
        else {
            ll minn = INFF;
            if(s[i - 1] <= s[i]) {
                minn = DP1[i - 1];
            }
            if(s1[i - 1] <= s[i]) {
                minn = min(minn, DP2[i - 1]);
            }
            DP1[i] = minn;
            minn = INFF;
            if(s[i - 1] <= s1[i]) {
                minn = DP1[i - 1] + a[i];
            }
            if(s1[i - 1] <= s1[i]) {
                minn = min ( minn , DP2[i - 1] + a[i]);
            }
            DP2[i] = minn;
        }
    }
    ll ANS = min(DP1[n - 1], DP2[n - 1] );
    if(ANS == INFF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ANS << endl;
}