class Solution:
    def minimumChairs(self, s: str) -> int:
        s = [1 if char == 'E' else -1 for char in s]
        res = 0 
        temp = 0
        for num in s:
            temp += num
            res = max(res, temp)
        return res