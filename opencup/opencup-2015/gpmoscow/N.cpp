/**
*/
#include<bits/stdc++.h>
using namespace std;

struct pc{
    double p;
    double w;
};
pc a[222];
int dp[222];
int main() {
    int n , t;
    cin >> t;
    while(t --) {
        cin >> n;
        int mx = 0;
        for(int i = 0; i < n; i ++) {
            cin >> a[i].p >> a[i].w;
        }
        for(int i = 0; i < n; i ++) {

            dp[i] = 1;

            for(int j = 0; j < i; j ++) {
                if(a[j].p < a[i].p && a[j].w > a[i].w)
                    dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
        for(int i = 0; i < n; i ++) {
            mx = max(mx , dp[i]);
        }
        cout<<mx<<endl;
   }
}
