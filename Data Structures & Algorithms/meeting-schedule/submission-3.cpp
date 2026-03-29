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
using namespace std;
class Solution {
public:

    // 
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() == 0) return true;
        
        sort(intervals.begin(),intervals.end(),[](const Interval& inter1, const Interval& inter2){
            return inter1.start <= inter2.start;
        });
        int most_recent_end = intervals[0].end;
        for(int i = 1; i < intervals.size() ; i++){
            if(intervals[i].start < most_recent_end) return false;
            else{
                most_recent_end = max(intervals[i].end, most_recent_end);
            }
        }
        return true;
    }
};
