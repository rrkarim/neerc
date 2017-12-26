#include <bits/stdc++.h>
#include <math.h>
#define INF 1000000000000000005
#define INFI 1073741824
#define MAXN 100005

using namespace std;
#define fir first
#define sec second
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;

ll n, d[MAXN + 2], pre[MAXN + 2];
pair<ll, ll> dx[5];

ll lims[5];

ll f(ll v, ll in, ll pres) {
    if(v == 1) {

        if(in == n) {
            return 0;
        }

        ll l = in, r = n - 1;
        while(true) {
            if(l >= r - 1) break;
            ll m = (l + r) / 2;
            if(abs(d[m] - dx[1].first) <= abs(d[m] - dx[2].first)) l = m;
            else r = m - 1;
        }
        if(l == r - 1)
            if(abs(d[r] - dx[1].first) <= abs(d[r] - dx[2].first))
                l = r;

        if(in == 7) {
            //cout << "**" << l << endl;
        }

        ll sz = l - in + 1;
        if(sz > dx[1].second) l -= (sz - dx[1].second);

        ll szl = n - in + 1;
        sz = l - in + 1;
        if(szl - sz > dx[2].second) {
            l += (szl - sz) - dx[2].second;
        }

        if(abs(d[l] - dx[1].first) > abs(d[l] - dx[2].first)) {
            l -= 1;
        }

        ll suml = 0, sumr = 0;

        if(lims[1] > in && lims[1] <= l) {
            suml += abs( (lims[1] - in)*dx[v].first - (pre[lims[1]-1] - pre[in] + d[in]) );
            suml += abs( (l - lims[1] + 1)*dx[v].first - (pre[l] - pre[lims[1]] + d[lims[1]]) );
        }
        else {
            if(l >= in)
                suml += abs((l - in + 1)*dx[1].first - (pre[l] - pre[in] + d[in]) );
        }



        if(lims[2] > l + 1 && lims[2] <= n) {
            sumr += abs( (lims[2] - (l + 1))*dx[2].first - (pre[lims[2]-1] - pre[l+1] + d[l+1]) );
            sumr += abs( ( (n-1) - lims[2] + 1)*dx[2].first - (pre[n-1] - pre[lims[2]] + d[lims[2]] ) );
        }
        else {
            if(n - 1 >= l + 1)
                sumr += abs(( (n-1) - (l + 1) + 1)*dx[2].first - (pre[n-1] - pre[l + 1] + d[l + 1]) );
            //if(in == 1) cout << n << endl;
        }
        //if(in == 4) {
            //cout << suml << " " << sumr << endl;
        //}
        return suml + sumr;

    }
    ll vm = 0;
    for(ll j = v + 1; j < 3; ++j) vm += dx[j].second;

    ll res = -1;

    ll st = 0;
    for(ll j = in; j < in + dx[v].second; ++j) {
        if(j < n)
            st += abs(dx[v].first - d[j]);
    }

    //cout << st << endl;

    for(ll i = dx[v].second; i >= 0; --i) {
        if(in + i >= n + 1) continue;

        if(n - i - pres <= vm) {
            if(res == -1)
                res = f(v + 1, in + i, pres + i) + st;
            res = min(res, f(v + 1, in + i, pres + i) + st);
        }
        st -= abs(dx[v].first - d[in + i - 1]);
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);

    for(ll i = 0; i < 3; ++i) cin >> dx[i].first >> dx[i].second;
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> d[i];

    sort(dx, dx + 3);
    sort(d, d + n);


    lims[0] = lims[1] = lims[2] = -1;

    for(ll i = 0; i < n; ++i) {
        if(d[i] > dx[0].first && lims[0] == -1)
            lims[0] = i;
        if(d[i] > dx[1].first && lims[1] == -1)
            lims[1] = i;
        if(d[i] > dx[2].first && lims[2] == -1)
            lims[2] = i;
    }

    pre[0] = d[0];
    for(ll i = 1; i < n; ++i) pre[i] = pre[i - 1] + d[i];



    for(ll i = 0; i < 3; ++i) {
        //cout << dx[i].first << " " << dx[i].second << endl;
    }

    //for(ll i = 0; i < n; ++i) cout << d[i] << " ";
    //cout << endl;

    cout << f(0, 0, 0) << endl;

}
