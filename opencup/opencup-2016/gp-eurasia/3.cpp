#include <bits/stdc++.h>
#include <string>
#define MAXN 100005
using namespace std;
typedef unsigned long long ll;
int inc0, inc1;
double mul;
string s1, s2;
int main() {
    ios_base::sync_with_stdio(0);
	cin >> s1 >> inc0 >> s2 >> mul >> inc1;
	double a = inc0 * mul;
	double b = inc1;
	if( fabs(a - b) < 0.0000001 ) {
        cout << "Whatever" << endl;
	}
	else if(a > b) {
        cout << "Power up, Evolve" << endl;
	}
	else {
        cout << "Evolve, Power up" << endl;
	}
}
