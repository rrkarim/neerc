/*
 *     Eternal vigilance is the price of liberalizm
 *     */
#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 3000004

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
int a[MAXN + 2];
int main() {
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    if(a[n - 2] == a[n - 1]) cout << "NO" << endl;
    else cout << "YES" << endl; 
    
}
