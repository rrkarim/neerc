#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 200005
#define INF 10000000000000
using namespace std;

typedef long long ll;
int n, x, y, s, f;
ll a[MAXN + 2], sum = 0; int used[MAXN + 2];
ll pth1[MAXN + 2], pth2[MAXN + 2];

ll solve(vector<ll>& vi) {
        vector<ll> pre, pos;
        int maxn = 0, curr = 0;
        for(int j = 0; j < vi.size(); ++j) {
            if(j == 0) {
                if(vi[j] <= 0) maxn = vi[j], curr = vi[j];
                else curr = vi[j];
                pre.push_back(maxn);
            }
            else {
                curr += vi[j];
                if(curr < maxn) maxn = curr;
                pre.push_back(maxn);
            }
        }
        maxn = 0, curr = 0;
        for(int j = vi.size() - 1; j >= 0; --j) {
            if(j == vi.size() - 1) {
                if(vi[j] <= 0)  maxn = vi[j], curr = vi[j];
                else curr = vi[j];
                pos.push_back(maxn);
            }
            else {
                curr += vi[j];
                if(curr < maxn) maxn = curr;
                pos.push_back(maxn);
            }
        }
        reverse(pos.begin(), pos.end());
        ll max_res = 0;
        for(int j = 0; j < pos.size(); ++j) {
            max_res = min(max_res, pre[j] + (j + 1 >= pos.size() ? 0 : pos[j + 1] ) );
        }
        max_res = min(max_res, pos[0]) * 2ll;
        return max_res;
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        sum = 0;
        scanf("%d", &n);
        for(int j = 0; j < n; ++j) scanf("%lld", a + j), sum += a[j];
        scanf("%d%d", &s, &f); s -= 1, f -= 1;
        vector <ll> vi1, vi2;
        int in = s;
        ll sum_ = 0ll, sum_0 = 0ll;
        for(int i = 0; i < n; ++i) {
            if(in == f) break;
            vi1.push_back(a[in]);
            sum_0 += a[in], in = (in + 1) % n;
        }
        ll max_res = solve(vi1);
        in = s;
        for(int i = 0; i < n; ++i) {
            in = (in - 1 < 0 ? n - 1 : (in - 1) % n);
            sum_ += a[in];
            vi2.push_back(a[in]);
            if(in == f) break;
        }
        ll ans = max_res + sum_;
        max_res = solve(vi2);
        ans = min(ans, max_res + sum_0);
        printf("%lld\n", ans);
    }
}
