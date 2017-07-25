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
#define MAXN 505

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int , int > ii ;

int const mod = 5, modl = 1e9 + 7;
int a[MAXN + 2][MAXN + 2], n, m, q;
string temp_;


ll binpow (int a, int n, ll mod_) {
	if (!n) return 1ll;
	if (n & 1) return (binpow (a, n-1, mod_) * a) % mod_;
	else {
		ll b = binpow (a, n/2, mod_);
		return (b * b) % mod_;
	}
}

int inverse(int n) {
    return (int) binpow(n, mod - 2, mod);
}

int rank_function() {
    m += q;
    const double EPS = 1E-9;
    int rank = max(n, m);
    vector<char> line_used (n);
    for (int i=0; i<m; ++i) {
        int j;
        for (j=0; j<n; ++j)
            if (!line_used[j] && abs(a[j][i]) > EPS)
                break;
        if (j == n)
            --rank;
        else {
            line_used[j] = true;
            for (int p=i+1; p<m; ++p)
                a[j][p] = (a[j][p] * inverse(a[j][i]) % mod) % mod;
            for (int k=0; k<n; ++k)
                if (k != j && a[k][i] != 0)
                    for (int p=i+1; p<m; ++p)
                        a[k][p] = (a[k][p] - a[j][p] * a[k][i] + mod) % mod;
        }
    }
    m -= q;
    return rank;
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < m; ++i) {
        cin >> temp_;
        for(int j = 0; j < n; ++j) {
            a[j][i] = (temp_[j] - 'a');
        }
    }
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> temp_;
        for(int j = 0; j < n; ++j) {
            a[j][i + m] = (temp_[j] - 'a');
        }
    }

    int rank_ = rank_function();
    ll ans = binpow(5, max(n, m) - rank_, modl);


    int max_i = -1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j])
                max_i = max(max_i, i);


    for (int i = 0; i < q; ++i) {
        int ind_col = m + i;
        int last = -1;
        for (int j = 0; j < n; ++j) {
            if (a[j][ind_col])
                last = j;
            if (last > max_i)
                break;
        }
        if (last > max_i)
            cout << 0 << "\n";
        else
            cout << ans << "\n";
    }

}
