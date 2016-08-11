#include <bits/stdc++.h>
#define MAXIMUS 100005
#define INFF 10000000000000

using namespace std;
typedef long long ll;

multiset <ll> S;
multiset <ll>::iterator it, main_it;
ll d;

ll solve(ll x) {
    string s;
    ll t = x;
    while(t) {
        if(t % 2) s += '1';
        else s += '0';
        t /= 2;
    }
    int tx = 32;

    while(s.length() != tx) s += '0';
    reverse(s.begin(), s.end());
    ll num = 0;
    main_it = S.end();
    for(int i = 0; i < tx; ++i) {
        if(s[i] == '0') {
            num += (1ll << (tx - 1 - i));
            it = S.lower_bound(num);

            if(it == main_it) {
                num -= (1ll << (tx - 1 - i));
            }
        }
        else {
            it = S.lower_bound(num);

            ll x = *it;

            if( x & (1 << (tx - 1 - i)) ) {
                num += (1ll << (tx - 1 - i));
            }

            main_it = S.lower_bound(num + (1ll << (tx - 1 - i)));

        }
    }
    return num;
}

int main() {
    int q; char c;
    cin >> q;
    S.insert(0ll);
    for(int i = 0; i < q; ++i) {
        scanf(" %c%I64d", &c, &d);
        if(c == '+') {
            S.insert(d);
        }
        else if(c == '-') {
            it = S.find(d);
            multiset<ll>::iterator newit = it;
            it++;
            S.erase(newit);
        }
        else {
            printf("%I64d\n", 1ll * (solve(d)^d));
        }
    }
}
