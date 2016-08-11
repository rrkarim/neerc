#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 100005
#define INFF 10000000000000
using namespace std;

typedef long long ll;

ll a[MAXN + 2];
string s[MAXN + 2], s1[MAXN + 2];
ll dp1[MAXN + 2], dp2[MAXN + 2];
int main() {
    ios_base::sync_with_stdio(0);

    int n; cin>>n;


    for(int i=0;i<n;++i) {

            cin>>a[i];

    }

    for(int i = 0; i < n; ++i) {

        cin >> s[i];

        string t = s[i];

        reverse(s[i].begin(), s[i].end());

        s1[i] = s[i];

        s[i] = t;


    }

    for(int i = 0; i < n; ++i) {

        if(i == 0) {

            dp1[i] = 0;

            dp2[i] = a[i];

        }

        else {

            ll minn = INFF;

            if(s[i - 1] <= s[i]) {

                minn = dp1[i - 1];

            }

            if(s1[i - 1] <= s[i]) {

                minn = min(minn, dp2[i - 1]);


            }

            dp1[i] = minn;


            minn = INFF;

            if(s[i - 1] <= s1[i]) {

                minn = dp1[i - 1] + a[i];

            }
            if(s1[i - 1] <= s1[i]) {

                minn = min ( minn , dp2[i - 1] + a[i]);

            }

            dp2[i] = minn;


        }

    }
    ll ANS = min(dp1[n - 1], dp2[n - 1] );

    if(ANS == INFF) {

        cout << -1 << endl;

        return 0;
    }
    cout << ANS << endl;

}

