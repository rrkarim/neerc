#include <bits/stdc++.h>
#include <string>
#define MAXN 100005
using namespace std;
typedef unsigned long long ll;
ll a[MAXN + 2];
map <pair<int,int>, int> mp;
int siz(ll a) {
    int len = 0;
    while(a) {
        len += 1;
        a /= 10;
    }
    return len;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        int sz = siz(a[i]);
        mp[{sz,a[i] % 7}] += 1;
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ll d = a[i];
        int l = siz(a[i]);
        int r = a[i] % 7;
        for(int j = 1; j <= 10; ++j) {
            d *= 10;
            int x = d % 7;
            int s = (7 - x) % 7;
            ans += mp[{j, s}];
            if(l == j && r == s) ans -= 1;
        }
    }
    cout << ans << endl;
}

