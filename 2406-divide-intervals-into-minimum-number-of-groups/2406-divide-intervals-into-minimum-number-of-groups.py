class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        s, e = [intervals[i][0] for i in range(n)], [intervals[i][1] for i in range(n)]
        s.sort()
        e.sort()
        output = 0
        s_i, e_i = 0, 0
        while s_i < n:
            if s[s_i] <= e[e_i]:
                s_i += 1
            else:
                e_i += 1
            output = max(output, s_i - e_i)
        return output