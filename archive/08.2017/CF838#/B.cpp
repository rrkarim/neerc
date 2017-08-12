#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 200004

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
        //cout << v << endl;
        t[v*2].add += t[v].add;
		t[v*2+1].add += t[v].add;
		t[v].mem += t[v].add;
		t[v].add = 0;
    }
    void add(int v, const int& tl, const int& tr, const int& l,
             const int& r, const ll& c) {
        //cout << v << " " << l << " " << r << " " << tl << " " << tr << endl;
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

int len;
Seg* S;
vector<pair<int,ll>> e[MAXN];
int n, q;
ll f[MAXN];
int be[MAXN], en[MAXN];
int tot;
int a[MAXN*2], b[MAXN*2], c[MAXN*2];

void dfs(int x, ll l) {
	tot++; be[x]=tot;
	S->add(1,1,n,tot,tot,l+f[x]);
	for (auto p : e[x])
		dfs(p.fir, l+p.sec);
	en[x] = tot;
}

ll path(int x) {
	return S->query(1,1,n,be[x],be[x])-f[x];
}

int main() {
	S = new Seg();
	scanf( "%d%d", &n, &q );
	for (int i = 1; i <= n-1; ++i) {
		scanf( "%d%d%d", &a[i], &b[i], &c[i] );
		e[a[i]].pb({b[i],c[i]});
	}
	for (int i = n; i <= 2*n-2; ++i) {
		scanf( "%d%d%d", &a[i], &b[i], &c[i] );
		f[a[i]] = c[i];
	}
	tot = 0;
	dfs(1, 0);
	for (int i = 1; i <= q; ++i) {
		int op, x, y;
		scanf( "%d%d%d", &op, &x, &y );
		if (op == 1) {
			if (x <= n-1)
				S->add(1,1,n,be[b[x]],en[b[x]],y-c[x]);
			else {
				S->add(1,1,n,be[a[x]],be[a[x]],y-c[x]);
				f[a[x]] = y;
			}
			c[x] = y;
		}
		else {
			ll px = path(x), py = path(y);
			if (be[y] >= be[x] && en[y] <= en[x])
				printf( "%I64d\n", py-px );
			else printf( "%I64d\n", S->query(1,1,n,be[x],en[x])-px+py );
		}
	}
}
