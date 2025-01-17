class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:

        xor_sum = 0
        
        for num in derived:
            xor_sum ^= num
       
        return xor_sum == 0   