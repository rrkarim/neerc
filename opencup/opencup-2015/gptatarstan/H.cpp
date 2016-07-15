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
ll res = 0, f = 0;
int main() {
    getline(cin, s);
    ll n, a; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        if(i % 2 == 0) {  res -= a; if(res != 0) f = 1; }
        else { res += a; if(res != 0) f = 1; }
    }
    if(res == 0) {

        if(n % 2 == 0) {
            cout << s << endl;
        }
        else {
            reverse(s.begin(), s.end());
            cout << s << endl;
        }

    }
    else {

        if(res < 0) {
            res *= -1;
            res %= s.length();
            string a = s.substr(0, res), b = s.substr(res);
            string t = b + a;
            if(n % 2 == 0) {
                cout << t << endl;
            }
            else {
                reverse(t.begin(), t.end());
                cout << t << endl;
            }
        }
        else {
            res %= s.length();
            string a = s.substr(0, s.length() - res), b = s.substr(s.length() - res);
            string t = b + a;
            if(n % 2 == 0) {
                cout << t << endl;
            }
            else {
                reverse(t.begin(), t.end());
                cout << t << endl;
            }
        }
    }

}

