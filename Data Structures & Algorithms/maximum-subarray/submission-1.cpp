class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int max_sum = nums[0];
        int sum = 0, end = 0, start = 0;
        while(start < nums.size() && end < nums.size()){
            sum += nums[end];
            if(sum > max_sum){
                max_sum = sum;
            }
            if(sum < 0){
                start = end + 1;
                end++;
                sum = 0;
                continue;
            }
            end++;
        }
        return max_sum;

    }
};
