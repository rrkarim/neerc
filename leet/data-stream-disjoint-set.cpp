#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
    set <int> S;
    set <int>::iterator it1, it2;
    map <int, int> u, s, e;
    set <pair<int, int> > se;
    set <pair<int, int> >::iterator it, _it;
    SummaryRanges() { }

    void addNum(int val) {
        if(u[val]) return;

        it1 = S.find(val - 1);
        it2 = S.find(val + 1);

        if(it1 != S.end() && it2 != S.end()) {
            it = se.upper_bound({val, val});
            _it = it;
            _it--;
            int first, last;
            last = (*it).second;
            se.erase(it);
            first = (*_it).first;
            se.erase(_it);
            se.insert({first, last});
        }
        else if(it1 != S.end()) {
            it = se.upper_bound({val, val});
            it--;
            int first = (*it).first;
            se.erase(it);
            se.insert({first, val});
        }
        else if(it2 != S.end()) {
            it = se.upper_bound({val, val});
            int last = (*it).second;
            se.erase(it);
            se.insert({val, last});
        }
        else {
            se.insert({val, val});
        }

        S.insert(val);

        u[ val ] = 1;
    }

    vector<Interval> getIntervals() {
        vector <Interval> r;
        r.push_back(Interval(1, 2));
        return r;
    }
};

int main() {
    SummaryRanges s = SummaryRanges();
    s.addNum(1);
    vector <Interval> t = s.getIntervals();
    s.addNum(3);
    t = s.getIntervals();

    for(int i = 0; i < t.size(); ++i) cout << t[i].start << " " << t[i].end << endl;

    s.addNum(7);
    t = s.getIntervals();
    s.addNum(2);
    t = s.getIntervals();
    s.addNum(6);
    t = s.getIntervals();
}
