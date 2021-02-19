class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals
        
        intervals.sort()
        i = 0

        while i < len(intervals):
            j = i+1
            merged = False
            while j < len(intervals):
                if intervals[j][0] <= intervals[i][1]:
                    merged = True
                    intervals[i][0] = min(intervals[i][0], intervals[j][0])
                    intervals[i][1] = max(intervals[i][1], intervals[j][1])
                    del intervals[j]
                j += 1
            if not merged:
                i += 1
        return intervals