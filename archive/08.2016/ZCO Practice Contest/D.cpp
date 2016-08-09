#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 200005
#define INF 1000000
using namespace std;

typedef long long ll;
int n;
ll x, k, sum;
vector <ll> a;
vector <ll>::iterator it;
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i) {
        ll x = k - 1 - a[i];
        it = upper_bound(a.begin(), a.end(), x);
        int dist = distance(a.begin(), it);
        if(x >= a[i]) dist -= 1;
        sum += dist;

    }

    cout << sum / 2 << endl;

}
