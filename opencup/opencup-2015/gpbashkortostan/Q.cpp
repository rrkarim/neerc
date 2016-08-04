#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n , m;
    cin >> t;
    while(t--) {
    cin >> n >> m;
    int dp[55];
    string s;
    cin >> s;
    fill_n(dp , 54 , 0);
    dp[0] = 0;
    for(int i = 1; i < n; i ++) {
        dp[i] = 2222222;
        if(s[i] == '.') {
            for(int j = 0; j < i; j ++) {
                if(s[j] == '.') {
                    if(i - j - 1 <= m)
                    dp[i] = min(dp[i] , dp[j] + 1);
                }
            }
        }
    }
    if(dp[n - 1] == 2222222)
        cout<<-1<<endl;
    else
    cout<<dp[n - 1]<<endl;
    }
    return 0;
}
