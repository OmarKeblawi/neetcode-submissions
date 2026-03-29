#include <functional>
#include <vector>
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int prev_max = 0, max_idx = 0, cur_idx = 0, d = 0;
        while(max_idx < nums.size() - 1){
            if(cur_idx > prev_max){
                prev_max = max_idx;
                d++;
            }
            max_idx = max(nums[cur_idx] + cur_idx, max_idx);
            cur_idx++;
        }
        return d+1;
    }
};
