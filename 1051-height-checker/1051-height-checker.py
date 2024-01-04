class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        c=0
        expected=sorted(heights)
        for i in range(len(heights)):
            if heights[i]!=expected[i]:
                c+=1
        return c