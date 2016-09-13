/**
 * Insert Interval
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int start = -1, end, index = -1, over = 0, u[intervals.size() + 2]; memset(u, 0, sizeof u);
        for(int i = 0; i < intervals.size(); ++i) {
            if(index == -1) {
                if(newInterval.start <= intervals[i].end && newInterval.end >= intervals[i].start) {
                    index = i;
                    start = min(intervals[i].start, newInterval.start);
                    end = max(intervals[i].end, newInterval.end);
                }
            }
            else {
                if(end < intervals[i].start) {
                    over = 1;
                    intervals[index].start = start;
                    intervals[index].end = end;
                    break;
                }
                else {
                    end = max(end, intervals[i].end);
                    u[i] = 1;
                }
            }
        }
        if(index == -1) {
            if(newInterval.end < intervals[0].start) {
                intervals.insert(intervals.begin(), newInterval);
            }
            else if(newInterval.start > intervals[intervals.size()-1].end) {
                intervals.push_back(newInterval);
            }
            else {
                int index = 0;
                for(int i = 0; i < intervals.size(); ++i) {
                    if(intervals[i].start > newInterval.end) {
                        index = i;
                        break;
                    }
                }
                intervals.insert(intervals.begin() + index, newInterval);
            }
            return intervals;
        }
        else {
            if(over == 0) {
                intervals[index].start = start;
                intervals[index].end = end;
                over = 1;
            }
        }
        vector <Interval> r;
        for(int i =0; i < intervals.size(); ++i) {
            if(!u[i]) r.push_back(intervals[i]);
        }
        return r;
    }
};