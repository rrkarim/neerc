#include <bits/stdc++.h>
#include <string>
#define MAXN 100005
#define MINF -100001
using namespace std;
typedef long long ll;

int a[104],par[101][MAXN+1];
int dp[104][MAXN + 2];
int n;
int f(int ind, int bonus) {
    if(dp[ind][bonus] != -1) {
        return dp[ind][bonus];
    }
    if(ind == n - 1) {
        return dp[ind][bonus] = max(0, a[ind] - bonus);
    }

    int minn = f(ind + 1, bonus + a[ind] / 100) + a[ind];
    int min2 = max(0, a[ind] - bonus) + f(ind + 1, max(bonus - a[ind], 0));
    if( minn < min2 ){
        par[ind][bonus] = bonus + a[ind] / 100;
    } else {
        par[ind][bonus] = max(bonus - a[ind], 0);
        minn = min2;
    }
    return dp[ind][bonus] = minn;
}

void path(int idx, int bonus){
    if(idx==n) return;
    int new_bouns = par[idx][bonus];
    if(new_bouns>bonus) cout << a[idx] << " + " << 0 << endl;
    else cout << max(0,a[idx]-bonus) << " + " << min(a[idx],bonus - new_bouns) << endl;
    path(idx+1,new_bouns);
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << endl;
    path(0,0);
}