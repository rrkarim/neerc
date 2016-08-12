/**
    Rasul Kerimov (CoderINusE)
    Generators
*/
#include <bits/stdc++.h>
#define MAXN 1000000
#define INF 2000000
#define _INF -20000000
#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

vector <pair<int,int> > ans;
int x, a, b, c, used[1004];

pair<int, int> xm[1005];

int main() {
    ios_base::sync_with_stdio(0);
    int n; ll k;
    { cin >> n >> k; }
    int minn = INF, sum = 0, index_to_change = -1;

    for(int i = 0; i < n; ++i) {
        memset(used, 0, sizeof used);
        { cin >> x >> a >> b >> c; }
        xm[0].first = x, xm[0].second = 0, used[ x ] = 1;
        int len = 0;
        for(len = 1; len <= 1205; ++len) {
            xm[len] = {(xm[len - 1].first * a + b) % c,len};
            if(used[ xm[len].first ]) break;
            used[ xm[len].first ] = 1;
        }

        sort(xm, xm + len);
        int mx = xm[len - 1].first, mx2 = -1, index = xm[len - 1].second, index2 = -1;

        for(int j = len - 2; j >= 0; --j) {
            if(mx == xm[j].first) continue;
            if( (mx - xm[j].first) % k != 0 ) {
                mx2 = xm[j].first;
                index2 = xm[j].second;
                break;
            }
        }
        if( mx - mx2 < minn && mx2 != -1) {
            minn = mx - mx2;
            index_to_change = i;
        }
        sum += mx;
        ans.push_back({index, index2});
    }


    if(sum % k != 0) {
        cout << sum << endl;
        for(int i = 0; i < n; ++i) cout << ans[i].first << " ";
        cout << endl;
        return 0;
    }
    if(minn == INF) cout << -1 << endl;
    else {
        cout << sum - minn << endl;
        for(int i = 0; i < n; ++i) {
            if(i == index_to_change) cout << ans[i].second << " ";
            else cout << ans[i].first << " ";
        }
        cout << endl;
    }

}
