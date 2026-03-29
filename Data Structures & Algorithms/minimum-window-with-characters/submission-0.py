class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # build histogram for t
        hist_t = {}
        for c in t:
            if c not in hist_t:
                hist_t[c] = 1
            else:
                hist_t[c] += 1

        #initaite start and end at index 0
        end = start = 0
        mini = min_start = min_end = -1
        hist = {}

        def CheckCorrect(hist, hist_t):
            for key in hist_t:
                if key not in hist or hist[key] < hist_t[key]:
                    return False
            return True

        while end < len(s):
            if s[end] in hist:
                hist[s[end]] += 1
            elif s[end] in hist_t:
                hist[s[end]] = 1

            while(CheckCorrect(hist , hist_t)):
                if (mini == -1) or ((end - start + 1) < mini):
                    mini = end - start + 1
                    min_start = start
                    min_end = end
                if s[start] in hist:
                    hist[s[start]] -=1
                start += 1
            end += 1
        return s[min_start : min_end + 1] if min_start != -1 else ""

      