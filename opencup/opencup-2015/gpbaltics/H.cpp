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
//const ll INF = 1.e18 + 2;
//const ll mod = 1000006;
const int MAXN = 1000005;
using namespace std;
vector<char> p (MAXN, '1');

int arr[MAXN + 1], median;

int quick_s(const int & n, int a[], int median) {
    if(n == 1 || median == 0) return a[0];
    int m = n / 2;
    m = a[m];
    int l[n + 1], r[n + 1], lsize = 0, rsize = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] <= m) l[lsize++] = a[i];
        else r[rsize++] = a[i];
    }
    if(lsize - 1 == median) return l[lsize - 1];
    else if(lsize - 1 > median) return quick_s(lsize, l, median);
    else {
        return quick_s(rsize, r, median - lsize - 1);
    }

}
ll A;


map <pair<ll, ll>, int> M;
int flaginf = 0;
bool f(int x) {
    ll temp = A + x;
    ll dt = x - 1;



    if(!dt) {
        if(!temp) {
            flaginf = 1;
            return true;
        }
        else return false;
    }
    if(temp % dt == 0) {
        int y = temp / dt;
        ll p =  -(x+y);
        ll q = 1ll * x * y;
        if(!M[{p, q}]) {
            //cout  << "x^2 + " << p << "x + " << q << " = 0" << endl;
            M[{p, q}] = 1;
            return true;
        }

    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> A;
    int res = 0;
    for(int i = -100000; i < 100000; ++i) {
            if(f(i)) res += 1;
            if(flaginf) {
                cout << "infinity" << endl;
                exit(0);
            }
    }
    cout << res << endl;
    return 0;
}
