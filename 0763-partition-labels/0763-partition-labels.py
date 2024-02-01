class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        intervals = {}
        for i, c in enumerate(s):
            if c not in intervals:
                intervals[c] = [i,i]
            else:
                intervals[c][1] = i
        intervals = list(intervals.values())
        intervals.sort()
        start, end = intervals[0][0], intervals[0][1]
        res = []
        for i in range(1, len(intervals)):
            if intervals[i][0] > end: # if interval is disjoint
                res.append(end - start + 1)
                start, end = intervals[i][0], intervals[i][1]
            else:
                end = max(end, intervals[i][1])
        res.append(end - start + 1)
        return res
        