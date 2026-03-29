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
#include <algorithm>
#include <functional>
class Solution {
public:

    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        vector<int> starts;
        vector<int> ends;
        for(const auto& interval : intervals){
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int count = 0, cnt_max = 0;
        int start_idx = 0, end_idx = 0;
        while(start_idx < starts.size()){
            while( start_idx < starts.size() && end_idx < ends.size() && starts[start_idx] < ends[end_idx]){
                start_idx++;
                count++;
                cnt_max = max(count, cnt_max);
            }
            while(start_idx < starts.size() && end_idx < ends.size() && starts[start_idx] >= ends[end_idx]){
                end_idx++;
                count--;
                cnt_max = max(count, cnt_max);
            }
        }
        return cnt_max;
    }
};
