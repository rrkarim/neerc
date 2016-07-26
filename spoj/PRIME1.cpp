/**
    Rasul Kerimov (CoderINusE)
    PRIME1 - Prime Generator
    Segmented sieve of Eratosthenes
*/
#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;
typedef pair<int,int> p;
typedef long long ll;

pair <int, int> a[MAXN + 2];
vector <int> primes;

void simple_eratosphen(ll limit) {
    int n = (int) sqrt(limit) + 1;
    int d[n + 200];
    memset(d, 0, sizeof(d));
    d[0] = d[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(!d[i]) {
            if(1ll * i * i <= n)
                for(int j = i * i; j <= n; j += i)
                    d[j] = 1;
        }
    }
    for(int i = 2; i <= n; ++i) {
        if(!d[i]) primes.push_back(i);
    }
}

void erat(ll n) {
    simple_eratosphen(n);
}

void segment(ll l, ll r) {
    int pr[r - l + 3000];
    memset(pr, 0, sizeof(pr));
    for(int i = 0; i < primes.size(); ++i) {

        ll left = (l / primes[i]) * primes[i];
        if(left < l) left += primes[i];

        if(left == primes[i]) left += primes[i];
        if(left > r) break;
        while(left <= r) {
            pr[left - l] = 1;
            left += primes[i];
        }
    }
    if(l == 1) pr[0] = 1;

    for(int i = 0; i < r - l + 1; ++i) {
        if(pr[i] == 0) {
            printf("%I64d\n", l + i);
        }
    }
    printf("\n");

}

int main() {
    int n; scanf("%d", &n);
    ll l, r;
    erat(1e9 + 1);

    for(int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &l, &r);
        segment(l, r);
    }
}
