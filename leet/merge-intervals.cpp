/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval &left, Interval &right) {
        return left.start < right.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector <Interval> r;
        int n = intervals.size();
        if(n == 0) return r;
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1; i < n; ++i) {
            if(intervals[i].start <= end) {
                end = max(end, intervals[i].end);
            }
            else {
                r.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        r.push_back(Interval(start, end));
        return r;
    }
};