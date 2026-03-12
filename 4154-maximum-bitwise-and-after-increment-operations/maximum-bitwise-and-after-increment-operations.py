class Solution:
    def maximumAND(self, nums: List[int], k: int, m: int) -> int:
        tot = 0; h = 1 << 30
        while h > 0:
            costs = [max(0, h - num) for num in nums]
            min_cost = sum(sorted(costs)[0:m])
            if min_cost <= k:
                k -= min_cost
                tot += h
                nums = [num-h if num >= h else 0 for num in nums]
            else:
                nums = [num-h if num >= h else num for num in nums]
            h >>= 1
        return tot