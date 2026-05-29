class Solution:
    def countDigitOccurrences(self, nums: list[int], digit: int) -> int:
        result = ''.join(map(str, nums))
        return result.count(str(digit))     