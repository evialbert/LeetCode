class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        def solve(intervals):
            far = 0
            cuts = 0
            for l,r in intervals:
                if far <= l:
                    cuts += 1
                far = max(far, r)
            return cuts - 1
        intervals = []
        for l,_,r,_ in rectangles:
            intervals.append((l,r))
        intervals.sort()
        maxcut = 0
        maxcut = solve(intervals)
        intervals = []
        for _,l,_,r in rectangles:
            intervals.append((l,r))
        intervals.sort()
        maxcut = max(maxcut, solve(intervals))
        return maxcut >= 2
