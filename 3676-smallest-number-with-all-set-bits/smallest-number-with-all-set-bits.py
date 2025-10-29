class Solution:
    def smallestNumber(self, n: int) -> int:
        return 2**len(f'{n:b}')-1