from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dict_occ = {oc: [] for oc in range(len(nums) + 1)}
        dict_nums = {}

        # Count frequency of each number
        for num in nums:
            dict_nums[num] = dict_nums.get(num, 0) + 1  # Increment count

        # Add numbers to frequency buckets
        for num, freq in dict_nums.items():
            dict_occ[freq].append(num)  # Store number in the correct frequency list

        # Collect the top K frequent elements
        klist = []
        cnt = k
        for i in range(len(nums), 0, -1):  # Iterate from highest frequency down
            for num in dict_occ[i]:
                if cnt == 0:
                    return klist  # Stop when we collect k elements
                klist.append(num)
                cnt -= 1

        return klist
        