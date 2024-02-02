class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        A_sum=sum(aliceSizes)
        B_sum=sum(bobSizes)
        b=set(bobSizes)
        average_sum=(A_sum+B_sum)//2
        for i in aliceSizes:
            if (average_sum-A_sum+i) in b:
                return [i,average_sum-A_sum+i]
                