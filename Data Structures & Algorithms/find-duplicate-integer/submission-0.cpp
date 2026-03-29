#include <unordered_map>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 2) return 1;
        
        unordered_map<int,int> m;


        for(int num: nums){
            m[num]++;
            if(m[num] >= 2){
                return num;
            } 
        }
    }
};
