class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        reversed = arr[::-1]
        maxToRight = -1
        for i in range(len(reversed)):
            temp = reversed[i]
            reversed[i] = maxToRight
            maxToRight = max(temp, maxToRight)
        return reversed[::-1]