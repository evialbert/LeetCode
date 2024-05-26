class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
    
        count = Counter(nums)
        xor=0
        for num, cnt in count.items():
            if(cnt==2):
                xor^=num
        return xor