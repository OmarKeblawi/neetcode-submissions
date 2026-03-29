from typing import List

class Solution:
    def aux_LIS(self, nums: List[int], index: int) -> int:
        if index == len(nums) - 1:
            return 1
        
        max_list = [self.aux_LIS(nums, i) + 1 for i in range(index + 1, len(nums)) if nums[index] < nums[i]]
        max_list.append(1)  # If no increasing sequence is found, return 1.
        
        return max(max_list)
    
    def lengthOfLIS(self, nums: List[int]) -> int:
        return max(self.aux_LIS(nums, i) for i in range(len(nums)))  # Start LIS from each index



        
        