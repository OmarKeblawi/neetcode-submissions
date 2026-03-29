#include <algorithm>
class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& int1, vector<int>& int2 ){
            return int1[1] < int2[1];
        });
        res.push_back(intervals[0]);
        for(auto& interval: intervals){
            auto& last = res.back();
            if(last[1] <= interval[0]){
                res.push_back(interval);
            }
        }

        return intervals.size() - res.size();
    }
};
