#include <bits/stdc++.h>
#define MAXN 1000002
using namespace std;
typedef long long ll;

ll popcount(ll n, int d) {
  ll result = 0;
  while (n != 0) {
    result += ((n%10) == d);
    n /= 10;
  }
  return result;
}

ll count(ll n, int d) {

  if (n < 10) return (d > 0 && n >= d);

  if ((n % 10) != 9) return popcount(n, d) + count(n-1, d);

  return 10*count(n/10, d) + (n/10) + (d > 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll a, b;
    while(true) {
        cin >> a >> b;
        if(!a && !b) break;
        if(a > b) swap(a, b);
        for(int i = 0; i <= 9; ++i) {
            if(i) cout << " ";
            ll res = count(b, i) - count(a - 1, i);
            cout << res;
        }
        cout << endl;
    }


}
