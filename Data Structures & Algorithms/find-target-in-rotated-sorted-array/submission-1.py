from typing import List

class Solution:
    def binary_search(self,nums: List[int], target: int , right: int, left: int)-> int:

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target :
                return mid
            elif nums[mid] < target:
                left = mid+1
            else:
                right = mid-1  
                
        return -1
        


    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        end = 0
        if len(nums) == 1:
            return -1 if target!= nums[0] else 0
        
        while left <= right:
            mid = left + (right -left) // 2
            if nums[mid] >  nums[mid+1] :
                end = mid
                break
            if nums[mid] > nums[right]:
                left = mid+1
            else:
                right = mid-1  
        
        right_index = self.binary_search( nums, target, end , 0)
        left_index = self.binary_search( nums, target, len(nums) - 1, end+1)
        
        return right_index if right_index != -1 else left_index