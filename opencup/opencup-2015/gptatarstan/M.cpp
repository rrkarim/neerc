/**
* DID YOU GET WHAT YOU WANTED FROM THIS LIFE?
* I DID....
* AND WHAT DID YOU WANT?
* TO CALL MYSELF BELOVED.
* TO FEEL MYSELF BELOVED ON THE EARTH....
*/
#include <bits/stdc++.h>
#define sz(x) (x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define ___WTHIT___ main
//#include <boost/accumulators/accumulators.hpp>
//#include <dirent.h>
//#include <stdio.h>
//#pragma comment(linker, "/STACK:16777216")
//#define M 300002
//#define pi 3.14159265358979323846
#define MINF -2000000000
//#define M  100005
#define K 28
using namespace std;
typedef long long ll;
//typedef long long ull;
const ll INF = 1.e18 + 2;
const ll mod = 1000000007;
const int MAXN = 100005;
using namespace std;
string s;
const int p = 203;
ll gcd ( ll a, ll b ) { ll c; while ( a != 0 ) { c = a; a = b%a; b = c; } return b; }
int main() {
    ll x, y, gcdn = 1, lcmn = 1;
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        if(i == 0) {
            lcmn = x;
            gcdn = y;
        }
        else {
            ll d = gcd(lcmn, x);
            lcmn = lcmn * x / d;
            gcdn = gcd(gcdn, y);

        }
    }
    cout  << lcmn << " "<< gcdn << endl;
}

