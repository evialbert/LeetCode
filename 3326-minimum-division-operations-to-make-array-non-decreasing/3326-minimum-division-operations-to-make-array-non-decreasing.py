class Solution:
    def minOperations(self, nums: List[int]) -> int:
        op = 0
        n = len(nums)

        for i in range(n-2,-1,-1):
            if nums[i]<=nums[i+1]:
                continue

            found = False
            for div in range(2, math.isqrt(nums[i])+1):
                if nums[i]%div == 0:
                    if div <= nums[i+1]:
                        nums[i] = div
                        found = True
                        op+=1
                    break

            if not found:
                return -1
        
        return op