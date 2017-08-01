/**
* DID YOU GET WHAT YOU WANTED FROM THIS LIFE?
* I DID....
* AND WHAT DID YOU WANT?
* TO CALL MYSELF BELOVED.
* TO FEEL MYSELF BELOVED ON THE EARTH....
*/
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 1000005

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;

/*
void input() {

    cin >> n >> k >> b;
    for(int i = 0; i < n; ++i) {
        cin >> a_ >> b_;
        d[i] = {a_, b_};
    }
    sort(d, d + n, cmp);
    for(int i = 0; i < n; ++i) {
        if(d[i].first == 1) {
            ;d1[]
        }
        else {

        }
    }

}
*/
int n, t; ll ans, k, sum, a[1005], dk;
vector<ll> d;

int main() {
    scanf("%d%lld", &n, &k);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        for(ll j = 1; j * j <= a[i]; ++j) {
            d.push_back(j);
            d.push_back((a[i] + j - 1) / j);
        }
    }
    dk = sum + k;

    d.push_back(INT_MAX);

    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    for(int i = 0; i < d.size() - 1; ++i) {
        ll sum_ = 0;
        for(int j = 0; j < n; ++j)
            sum_ += (a[j] + d[i] - 1) / d[i];
        sum_ = dk / sum_;
        if(d[i] <= sum_) ans = max(ans, sum_);
    }
    printf("%d\n", ans);

}
