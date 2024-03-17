class Solution:
    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        s = 0
        def encrypt(x):
            x = list(str(x))
            m = max(x)
            for i in range(len(x)):
                x[i] = m
            return int(''.join(x))
        
        for num in nums:
            s += encrypt(num)
        return s