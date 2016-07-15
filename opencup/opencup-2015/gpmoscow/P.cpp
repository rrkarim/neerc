#include <bits/stdc++.h>
#define MAXN 1000002
using namespace std;
typedef long long ll;

struct elem {
    ll x, y;
    elem() {}
    elem(ll x, ll y) : x(x), y(y) { }
    bool operator<(const elem &second) const {
        return x < second.x;
    }
};

set <elem> S;
set<elem>::iterator it;
ll l, r;

void insert_set(ll l, ll r) {
            it = S.upper_bound({l, l + r - 1});

            elem ra = *it; it--;
            elem la = *it;

            if(la.y + 1 >= l && ra.x - 1 <= (l + r - 1)) {

                    set<elem>::iterator temp = it;
                    printf("%lld %lld\n", la.y + 1, ra.x - 1);

                    S.erase(++it);
                    S.erase(temp);
                    S.insert({la.x, ra.y});

                }
                else {
                    if(l <= la.y + 1) {

                        ll left = la.x, right = la.y + r;
                        S.erase(it);

                        printf("%lld %lld\n", la.y + 1, min(right, ra.x - 1));
                        S.insert({left, min(right, ra.x - 1)});
                    }
                    else if((l + r - 1) >= ra.x - 1 ) {
                        S.erase(++it);

                        printf("%lld %lld\n", l, ra.x - 1);
                        S.insert({ l, ra.y });
                    }
                    else {

                        printf("%lld %lld\n", l, l + r - 1);
                        S.insert({l, l + r - 1});
                    }

                }
}
int main() {

    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
    int n;
    int m; cin >> n >> m;
    cout << m + 2 - n << endl;
    }
}
