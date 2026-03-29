#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),[&](const vector<int>& int1, const vector<int>& int2){
            return int1[0] < int2[0];
        });
        unordered_map<int,queue<int>> indices;
        for(int i = 0; i < queries.size(); i++){
            indices[queries[i]].push(i);
        }
        sort(queries.begin(),queries.end());
        auto comp = [&](const vector<int>& int1, const vector<int>& int2){
            return int1[0] > int2[0]; //min-heap by interval length.
        };
        priority_queue<vector<int>, vector<vector<int>>,decltype(comp)> minHeap(comp);
        vector<int> result = vector<int>(queries.size(), -1);
        int int_idx = 0; 
        for(const auto& q : queries){
            while(int_idx < intervals.size() && intervals[int_idx][0] <= q){
                if(intervals[int_idx][1] >= q){
                    minHeap.push({intervals[int_idx][1] - intervals[int_idx][0] + 1, intervals[int_idx][1]});
                }
                int_idx++; 
            }
            while((!minHeap.empty()) && minHeap.top()[1] < q) minHeap.pop();
            if(!minHeap.empty()){
                int q_idx = indices[q].front();
                result[q_idx] = minHeap.top()[0];
                indices[q].pop();
            }
        }
        return result;
    }
};
