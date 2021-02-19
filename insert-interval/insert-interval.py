class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        merged = []
        n = len(intervals)
        i,start,end = 0,0,1
        while i<n and intervals[i][end]<newInterval[start]:#skip and add all the intervals that come before the new_Interval.
            merged.append(intervals[i])
            i+=1
        while i<n and intervals[i][start]<=newInterval[end]:#merge all the intervals that overlap with newInterval
            newInterval[start] = min(intervals[i][start],newInterval[start])
            newInterval[end] = max(intervals[i][end],newInterval[end])
            i+=1
        merged.append(newInterval)#append the new merged Interval
        
        while i<n:#append remaining intervals into the merged array
            merged.append(intervals[i])
            i+=1
        return merged
          