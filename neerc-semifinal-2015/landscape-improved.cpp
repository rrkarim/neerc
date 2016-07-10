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
ll pre_sum[MAXN + 2];
ll sums[MAXN + 2], maxl, sz, tl = 30267;

int indexes_update[MAXN + 2];

void get_sum(const ll &m) {
    ll curr = m - 1;
    for(int i = 1; i <= w + 1; ++i) {
        if(curr < 0) break;
        if(i == 1) sums[i] = curr--;
        else sums[i] = sums[i - 1] + curr--; 
    }
    ll sum = h[1];
    pre_sum[1] = sum;
    for(int i = 2; i <= w; ++i) {
        pre_sum[i] = pre_sum[i - 1] + h[i];
    }
}
void get_left(const ll &m) {
    int index_l = 0, curr_index = 1;
    ll maxn = -1;
    for(int i = 1; i <= w; ++i) {
        curr_index = max(curr_index, indexes_update[i]);
        indexes_update[min(1ll * w, i + (m - h[i]))] = i + 1;
        maxn += 1;
        maxn = max(h[i], maxn);
        if(maxn == m) {
            index_l = i;
            break;
        }
    }
    for(int i = 1; i <= index_l; ++i) l_stones[i] = INF;
    for(int i = index_l; i <= w; ++i) {
        curr_index = max(curr_index, indexes_update[i]);
        indexes_update[min(1ll*w, i + (m - h[i]))] = i + 1;
        ll sum = sums[i - curr_index] - pre_sum[i - 1] + pre_sum[curr_index - 1];
        l_stones[i] = sum;
    }
}
void get_right(const ll &m) {
    int index_l = 0, curr_index = 1;
    ll maxn = -1;
    for(int i = 1; i <= w; ++i) {
        curr_index = max(curr_index, indexes_update[i]);
        indexes_update[min(1ll * w, i + (m - h[i]))] = i + 1;
        maxn += 1;
        maxn = max(h[i], maxn);
        if(maxn == m) {
            index_l = i;
            break;
        }
    }
    for(int i = 1; i <= index_l; ++i) r_stones[i] = INF;
    for(int i = index_l; i <= w; ++i) {
        curr_index = max(curr_index, indexes_update[i]);
        indexes_update[min(1ll * w, i + (m - h[i]))] = i + 1;
        ll sum = sums[i - curr_index] - pre_sum[i - 1] + pre_sum[curr_index - 1];
        r_stones[i] = sum;
    }
}
ll get_res(ll n) {       
    if( maxl < n ) return INF;
    for(int i = 1; i <= w; ++i)     if(h[i] >= n) return 0;
    get_sum(n);
    get_left(n);
    memset(indexes_update, 0, sizeof indexes_update);
    reverse(h + 1, h + w + 1);
    get_sum(n);
    get_right(n);
    reverse(h + 1, h + w + 1);
    reverse(r_stones + 1, r_stones + w + 1);
    ll res = INF;
    for(int i = 1; i <= w; ++i) {
        if(h[i] >= n) return 0ll;
        ll t = l_stones[i] + r_stones[i] + (n - h[i]);
        res = min(res, t);
    }
    return res;
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> w >> have;
    for(int i = 1; i <= w; ++i)
        cin >> h[i];
    ll lt = 0, rt = 2 * 1e9;
    int l = 1, r = w;
    ll lefts = h[l], rights = h[r];
    l += 1, r -= 1;
    while(l <= r) {
        ll ltemp = max(lefts + 1, h[l]);
        ll rtemp = max(rights + 1, h[r]);
        if(ltemp <= rtemp) {
            lefts = ltemp;
            l += 1;
        }
        else {
            rights = rtemp;
            r -= 1;
        }
    }

    maxl = max(lefts, rights);
    int k = 0;
    while(lt < rt) {
        ll mid = (lt + rt + 1) / 2;
        ll t = get_res(mid); 
        if(get_res(mid) <= have)
            lt = mid;
        else rt = mid - 1;
        assert(k < 60);
        k += 1;
    }
    cout << lt << endl;
}
