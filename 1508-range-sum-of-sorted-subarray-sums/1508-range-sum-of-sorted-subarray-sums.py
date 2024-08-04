class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        l1 = []
        for i in range(n):
            total = nums[i]
            for j in range(i,n-1):
                l1.append(total)
                total += nums[j+1]
            l1.append(total)
        l1.sort()
        output = 0
        while left <= right:
            output += l1[left-1]
            left += 1
        return output%1000000007