class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        count = Counter(nums)                   # solution 1: line sweep, TC = O(nlogn)
        presum = defaultdict(int)
        for x in count:                 # line sweep
            presum[x-k] += count[x]
            presum[x+k+1] -= count[x]
        keys = sorted(presum.keys() | count.keys())     # search all possible keys
        ans, total = 0, 0
        for x in keys:
            total += presum[x]                          # maximum frequency for x
            ops = min(total-count[x], numOperations)    # number of operations bounded by numOperations
            ans = max(ans, count[x] + ops)              # update ans
        return ans




        # nums.sort()                     # solution 2: binary search, TLE!!!
        # count = Counter(nums)
        # keys = sorted(count.keys())
        # ans = 0
        # for i in range(len(keys)):
        #     opset = {keys[i]}
        #     if i < len(keys) - 1:
        #         opset |= set(list(range(max(keys[i]+1, keys[i+1]-k), min(keys[i]+k, keys[i+1]-1) + 1)))
        #     for x in opset:
        #         left = bisect_left(nums, x) - bisect_left(nums, x-k)            # [x-k..x-1]
        #         right = bisect_right(nums, x+k) - bisect_right(nums, x)         # [x+1..x+k]
        #         cur = count[x] if x in count else 0
        #         cur += min(left+right, numOperations)
        #         ans = max(ans, cur)
        # return ans