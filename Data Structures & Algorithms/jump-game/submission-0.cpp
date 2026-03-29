class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_idx = nums[0];
        int cur_idx = 0;
        while(max_idx < nums.size() - 1  && cur_idx <= max_idx ){
            max_idx = max(cur_idx + nums[cur_idx] , max_idx);
            cur_idx++;
        }
        return (max_idx >= nums.size() - 1);
    }
};
