class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ABC = 26
        
        dist_hist = {}

        for string in strs:
            hist = [0] * ABC
            for c in string:
                hist[ord(c) - ord('a')] += 1
            hist_tuple = tuple(hist)
            if hist_tuple not in dist_hist:
                dist_hist[hist_tuple] = [string]
            else:
                dist_hist[hist_tuple].append(string)
        
        result = []
        for key in dist_hist:
            result.append(dist_hist[key])
        
        return result

