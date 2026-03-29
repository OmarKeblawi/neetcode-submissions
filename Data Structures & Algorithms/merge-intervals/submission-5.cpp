#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;
        vector<vector<int>> out;
        //sort by start (ascending) and then by end(descending).
        sort(intervals.begin(), intervals.end(), [&](vector<int>& int1, vector<int>& int2 ){
            if(int1[0] < int2[0] || ((int1[0] == int2[0]) && int1[1] < int2[1])){return true;}
            else{
                return false;
            }
        });
        out.push_back(intervals[0]);
        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1];
            int last_end = (out.back())[1];
            if(last_end >= start){
                out.back()[1] = max(last_end,end);
            }
            else{
                out.push_back(interval);
            }
        }
        return out;

    }
};
