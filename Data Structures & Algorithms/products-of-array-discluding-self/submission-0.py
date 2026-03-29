class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        cnt_zeros = 0
        zero_index = -1 
        for i in range(len(nums)):
            if nums[i] == 0:
                cnt_zeros += 1
                zero_index = i


        if cnt_zeros > 1:
            return [0]*len(nums)
        product = 1
        for i in range(len(nums)):
            if i == zero_index:
                continue
            product *= nums[i]
        out = [0] * len(nums)
        if zero_index != -1:
            out[zero_index] = product
        else:
            for i in range(len(nums)):
                out[i] = product // nums[i]
        return out
        




