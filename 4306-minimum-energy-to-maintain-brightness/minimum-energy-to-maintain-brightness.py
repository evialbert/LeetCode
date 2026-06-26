class Solution:
  def minEnergy(self, n: int, brightness: int,
                intervals: list[list[int]]) -> int:

    intervals.sort()
    time, (beg, end) = 0, intervals[0]

    for left, rght in intervals:
        
      if end < left:   # disjoint intervals
        time+= end - beg + 1
        beg, end = left, rght

      elif end < rght: # overlapping intervals
        end = rght

    return ceil(brightness/3) * (time + end - beg + 1)
  