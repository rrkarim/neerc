#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 200004

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

struct p {
    ll add, mem;
    p() {}
    p(const ll& add_, const ll& mem_) {
        this->add = add_, this->mem = mem_;
    }
    ll sum() { return this->add + this->mem; }
};

class Seg {
public:
    p t[MAXN*4];

    Seg() {
        memset(t, 0, sizeof t);
    }

    void update(int v) {
        t[v].mem = min(t[v*2].mem + t[v*2].add, t[v*2+1].mem + t[v*2+1].add);
    }
    void push(int v) {
        t[v*2].add += t[v].add;
		t[v*2+1].add += t[v].add;
		t[v].mem += t[v].add;
		t[v].add = 0;
    }
    void add(int v, const int& tl, const int& tr, const int& l,
             const int& r, const ll& c) {
        if(l <= tl && r >= tr) {
            t[v].add += c;
            return;
        }
        int m = (tl + tr) >> 1;
        push(v);
        if(l <= m) add(v*2, tl, m, l, r, c);
        if(r > m)  add(v*2+1, m+1, tr, l, r, c);
        update(v);
    }
    ll query(int v, const int& tl, const int& tr,
             const int& l, const int& r) {
        if(l <= tl && r >= tr) return t[v].sum();
        int m = (tl + tr) >> 1;
        push(v);
        ll ret = INF;
        if(l <= m) ret = min(ret, query(v*2, tl, m, l, r));
        if(r > m) ret = min(ret, query(v*2+1, m+1, tr, l, r));
        return ret;
    }
};

int n, q, a, b, c, in[MAXN + 2], out[MAXN + 2], pre[MAXN + 2];
pair<int, int> pl[MAXN + 2];
vector <vector <pair<int, int>>> g;
vector <int> gaus_array, f;
pair <int, int> vals[MAXN + 2];

pair <int, int> mp[MAXN + 2];

int len;
Seg* seg;

void dfs(int v) {
    gaus_array.push_back(v);
    in[v] = gaus_array.size();
    for(int i = 0; i < g[v].size(); ++i) dfs(g[v][i].first);
    gaus_array.push_back(v);
    out[v] = gaus_array.size();
}

void init(int v, ll sum) {
    pre[v] = sum;
    seg->add(1, 1, len, in[v], out[v], sum + f[v] - seg->query(1, 1, len, in[v], in[v]));
    for(int i = 0; i < g[v].size(); ++i)
        init(g[v][i].first, sum + g[v][i].second);
}

int main() {
    seg = new Seg();

    scanf("%d%d", &n, &q);

    g.resize(n + 1), f.resize(n + 1);

    for(int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back({b, c});
        pl[b] = {a, c};
        mp[i + 1] = {a, b};
        vals[i + 1] = {a, c};
    }

    for(int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        f[a] = c;
        mp[i + n] = {a, 1};
        vals[i + 1] = {a, c};
    }
    dfs(1);
    len = gaus_array.size();
    init(1, 0);
    for(int i : gaus_array) cout << i << " "; cout << endl;

    for(int i = 0; i < q; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1) {
            if(b < n) {
                pl[mp[b].second].second = c;
                seg->add(1, 1, len, in[vals[b].first]+1, out[vals[b].first]-1, c - vals[b].second);
                vals[b].second = c;
            }
            else {
                seg->add(1, 1, len, in[vals[b].first], in[vals[b].second], c - vals[b].second);
                seg->add(1, 1, len, in[vals[b].first], out[vals[b].second], c - vals[b].second);
                vals[b].second = c;
            }
        }
        else {
            ll ans = min( seg->query(1, 1, len, in[b], out[b]) - pre[b] + pre[c], seg->query(1, 1, len, in[c], out[c]) - pre[c] + pre[b] );
            if(in[b] < in[c] && out[b] > out[c]) {
                ll sum = 0;
                while(c != b) {
                    sum += pl[c].second;
                    c = pl[c].first;
                }
                ans = min(sum, ans);
            }
            if(in[c] < in[b] && out[c] > out[b]) {
                ll sum = 0;
                while(b != c) {
                    sum += pl[b].second;
                    b = pl[b].first;
                }
                ans = min(sum, ans);
            }

            printf("%I64d\n", ans);
        }
    }
}
