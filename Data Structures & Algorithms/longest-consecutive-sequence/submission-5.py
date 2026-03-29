class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numsTosets = {}
        max_len = 0
        for num in nums:
            if num not in numsTosets:
                if num - 1 in numsTosets and num + 1 in numsTosets:
                    numsTosets[num - 1].append(num)
                    numsTosets[num - 1] += numsTosets[num + 1]
                    numsTosets[num + 1] = numsTosets[num] = numsTosets[num - 1]
                    print(num ,len(numsTosets[num]))
                    max_len = len(numsTosets[num]) if len(numsTosets[num]) > max_len else max_len
                elif num - 1 in numsTosets:
                    numsTosets[num - 1].append(num)
                    numsTosets[num] = numsTosets[num - 1]
                    print(num ,len(numsTosets[num]))
                    max_len = len(numsTosets[num]) if len(numsTosets[num]) > max_len else max_len
                elif num + 1 in numsTosets:
                    numsTosets[num + 1].append(num)
                    numsTosets[num] = numsTosets[num + 1]
                    max_len = len(numsTosets[num]) if len(numsTosets[num]) > max_len else max_len
                    print(num ,len(numsTosets[num]))
                else:
                    numsTosets[num] = [num]
                    max_len = len(numsTosets[num]) if len(numsTosets[num]) > max_len else max_len
                    print(num ,len(numsTosets[num]))
        return max_len
        

        