class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sxor = 0;
        for(int i = 1 ; i <= nums.size(); i++){
            sxor ^= i;
        }
        for(int num : nums){
            sxor^= num;
        }
        return sxor;
    }
};
