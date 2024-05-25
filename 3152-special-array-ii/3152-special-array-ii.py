class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        ps = [0] * n

        for i in range(1, n):
            ps[i] = nums[i] % 2 == nums[i - 1] % 2
            if i:
                ps[i] += ps[i - 1]
        
        ans = []
        for v in queries:
            l, r = v
            sum_val = ps[r] - ps[l]
            ans.append(sum_val == 0)

        return ans