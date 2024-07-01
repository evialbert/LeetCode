class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        
        def fn(d):
            """Return True if d is a feasible distance."""
            ans, prev = 0, -inf # where previous ball is put
            for x in position:
                if x - prev >= d: 
                    ans += 1
                    if ans == m: return True
                    prev = x
            return False 
        
		# "last True" binary search (in contrast to "first True" binary search)
        lo, hi = 1, position[-1] - position[0]
        while lo < hi: 
            mid = lo + hi + 1 >> 1
            if fn(mid): lo = mid
            else: hi = mid - 1
        return lo