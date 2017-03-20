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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        std::vector<Interval> result;
        std::sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){ return a.start < b.start; });
        result.push_back(intervals[0]);
        for (int i = 1; i != intervals.size(); ++i) {
            if (intervals[i].start > result.back().end) {
                result.push_back(intervals[i]);
            } else {
                result.back().end = result.back().end > intervals[i].end ? result.back().end : intervals[i].end;
            }
        }
        return result;
    }
};