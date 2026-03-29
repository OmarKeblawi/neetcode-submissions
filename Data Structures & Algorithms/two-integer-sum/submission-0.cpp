#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> map;
        for(int i = 0; i < nums.size() ; i++){
            map[nums[i]].push_back(i);
        }

        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] == target - nums[i] && (map[nums[i]].size() >= 2) )
            {
                return {map[nums[i]][0], map[nums[i]][1]};
            }
            else if(nums[i] != target - nums[i] && map[nums[i]].size() > 0 && map[target - nums[i]].size() > 0){
                return {map[nums[i]][0], map[target - nums[i]][0]};
            }
        }
    }
};
