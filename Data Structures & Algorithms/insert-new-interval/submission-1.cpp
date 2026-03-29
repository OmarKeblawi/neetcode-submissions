#include <functional>
class Solution {
public:
    vector<int> unite(vector<int> int1, vector<int> int2){
        return {min(int1[0],int2[0]), max(int1[1],int2[1])};
    }
    bool isCommon(vector<int> int1, vector<int> int2){
        return (int1[0] <= int2[0] && int1[1] >= int2[0]) || (int2[0] <= int1[0] && int2[1] >= int1[0]);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = 0, right = intervals.size() - 1;
        int res1 = -1, res2 = -1;
        int start = newInterval[0];
        int end = newInterval[1];
        //find the start of unification
        while(left <= right){
            int mid = (left + right) /2;
            if(isCommon(intervals[mid],newInterval)){
                right = mid - 1;
                res1 = mid;
            }
            else if(intervals[mid][0] > start){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        //united if needed
        if(res1 != -1){
            newInterval = unite(intervals[res1], newInterval);
            start = newInterval[0];
            end = newInterval[1];
        }
        left = 0;
        right = intervals.size() - 1;
        //find the end of unification
        while(left <= right){
            int mid = (left + right) /2;
            if(isCommon(intervals[mid],newInterval)){
                left = mid + 1;
                res2 = mid;
            }
            else if(intervals[mid][0] > end){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(res2 != -1){
            newInterval = unite(intervals[res2], newInterval);
            start = newInterval[0];
            end = newInterval[1];
        }

        if(res1 != -1 && res2 == -1 || ((res1 == res2) && res1 != -1) ){
            intervals[res1] = newInterval;
            return intervals;
        }
        if(res2 != -1 && res1 == -1){
            intervals[res2] = newInterval;
            return intervals;
        }
        if(res1 == -1 && res2 == -1){
            int i = 0;
            while(i < intervals.size() && intervals[i][0] < start) i++;

            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        }
        if(res1 != -1 && res2 != -1){
            intervals.erase(intervals.begin() + res1 , intervals.begin() + res2 + 1);
            intervals.insert(intervals.begin() + res1, newInterval);
        }

        return intervals;
    }
};
