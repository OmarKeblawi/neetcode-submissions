/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
#include<algorithm>
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return true;
        sort(intervals.begin(),intervals.end(),[&](Interval& int1, Interval& int2){
            return int1.end < int2.end;
        });
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size() ; i++){
            const auto& last = res.back();
            if(last.end <= intervals[i].start){
                res.push_back(intervals[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};
