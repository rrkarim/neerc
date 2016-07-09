/**
    Rasul Kerimov (CoderINusE)
    Landscape Improved
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

int w;
ll have, h[MAXN + 2];
ll l_stones[MAXN + 2], r_stones[MAXN + 2], events[MAXN + 2];

ll get_res(ll n) {

    //l_stones[1] = 0, r_stones[w] = 0;

    //check
    ll lefts = h[1], rights = h[w];
    for(int i = 2; i <= w - 1; ++i) {
        if(lefts > rights) rights += 1;
        else lefts += 1;
    }
    if( min(lefts, rights) < n ) return INF;
    //

    int fl = 0, fr = 0;
    for(int i = 1; i <= w; ++i) {
        if(h[i] >= n) return 0;
        if(fl == 0) l_stones[i] = 0ll;
        else l_stones[i] = max(0ll, n - h[i - 1] - 1);
        if(h[i] + 1 == n && !fl) fl = i;
    }
    for(int i = 1; i <= fl; ++i) l_stones[i] = INF;

    for(int i = w; i >= 1; --i) {
        if(fr == 0) r_stones[i] = 0ll;
        else r_stones[i] = max(0ll, n - h[i + 1] - 1);
        if(h[i] + 1 == n && !fr) fr = i;
    }
    for(int i = w; i >= fr; --i) r_stones[i] = INF;
    ll res = INF;



    for(int i = 1; i <= w; ++i) {
        if(h[i] >= n) return 0ll;
        ll t = l_stones[i] + r_stones[i] + (n - h[i]);
        //cout << l_stones[i] << " " << r_stones[i] << " " << t << endl;
        res = min(res, t);
    }
    return res;
}

 void getNeed(long middle) {
            ll res[MAXN + 2];
            ll psum[MAXN + 2];
            for (int i = 0; i < w; ++i) psum[i + 1] = psum[i] + h[i];
            int stackPos[MAXN + 2];
            int sp = 0;
            for (int i = 0; i < w; ++i) {
                int left = -1;
                int right = sp;
                while (right - left > 1) {
                    int mid = (left + right) / 2;
                    if (middle - i <= h[stackPos[mid]] - stackPos[mid]) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
                if (left >= 0) {
                    int cnt = i - stackPos[left];
                    res[i] = (middle + (middle - cnt + 1)) * cnt / 2;
                    res[i] -= psum[i + 1] - psum[stackPos[left] + 1];
                } else {
                    res[i] = INF;
                }
                while (sp > 0 && h[i] - i > h[stackPos[sp - 1]] - stackPos[sp - 1]) {
                    --sp;
                }
                stackPos[sp] = i;
                ++sp;
            }
            for(int i = 0; i < w; ++i)
                cout << res[i] << " ";
            cout << endl;

        }

int main() {
    ios_base::sync_with_stdio(0);
    cin >> w >> have;
    for(int i = 1; i <= w; ++i)
        cin >> h[i];

    ll lt = 0, rt = 2 * 1e9;

    cout << getNeed(5) << endl;
    return 0;
    int k = 0;
    while(lt < rt) {
        ll mid = (lt + rt + 1) / 2;
        //cout << mid << " " << get_res(mid) << endl;
        //cout << lt << "-" << rt << endl;
        if(get_res(mid) <= have)
            lt = mid;
        else rt = mid - 1;
        assert(k < 50);
        k += 1;
    }

    cout << lt << endl;


}
