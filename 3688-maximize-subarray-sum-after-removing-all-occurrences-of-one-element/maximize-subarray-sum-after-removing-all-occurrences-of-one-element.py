class Solution:
    def maxSubarraySum(self, nums: List[int]) -> int:
        prefix_sums = collections.defaultdict(lambda: 0)
        prefix_sums[0] = 0

        res = float('-inf') 
        pre_sum = 0
        lowest = 0

        for num in nums:
            pre_sum += num
            res = max(res, pre_sum - lowest)

            if num < 0:
                prefix_sums[num] = num + min(prefix_sums.get(num, 0), prefix_sums[0])
                lowest = min(lowest, prefix_sums[num])

            neg_pre_sum = prefix_sums[0]
            prefix_sums[0] = min(neg_pre_sum, pre_sum)
            lowest = min(lowest, neg_pre_sum)

        return res