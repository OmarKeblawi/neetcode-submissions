class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_product = 1;
        int zero_cnt = 0;
        int zero_idx = -1;
         for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0) {
                zero_cnt++;
                if(zero_cnt >= 2){
                    return vector<int>(nums.size(),0);
                }
                zero_idx = i;
                continue;
            }
            total_product *= nums[i]; 
        }
        
        vector<int> out;
        if(zero_cnt == 0){
            for(int i = 0 ; i < nums.size(); i++){
                out.push_back((int)(total_product / nums[i]));
            }
        }
        else{
            out = vector<int>(nums.size(),0);
            out[zero_idx] = total_product;
        }
        return out;
    }
};
