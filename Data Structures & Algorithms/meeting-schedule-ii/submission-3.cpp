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
#include <queue>
using namespace std;
class Solution {
public:

    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        if(intervals.size() == 1) return 1;

        priority_queue<int, vector<int>, greater<int>> s;
        priority_queue<int, vector<int>, greater<int>> e;

        for(const auto& inter: intervals){
            s.push(inter.start);
            e.push(inter.end);
        }
        int cur_cnt = 0;
        int max_cnt = 0;
        while(!s.empty()){
            if(s.top() < e.top()){
                    s.pop();
                    cur_cnt++;
            }
            else{
                e.pop();
                cur_cnt--;
            }
            max_cnt = max(max_cnt, cur_cnt);
        }
        return max_cnt;
    }
};

//intervals = [(0,30),(5,10),(10,15)]
// s: [10]
// e: [10,15,30]
//  cnt = 2;
// max_cnt = 2
// 