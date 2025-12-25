class Solution:
    def numGoodSubarrays(self, nums: List[int], k: int) -> int:
        nums.append(0) # dummy
        seen_remainder = defaultdict(int)
        seen_remainder[0] = 1
        ret = 0
        i = 0
        count_continuous = 1
        currSum = 0
        while i < len(nums) - 1:
            if nums[i] == nums[i+1]:
                count_continuous += 1
            else:
                prev = nums[i]
                # count using mod k method
                old_currSum = currSum
                for _ in range(count_continuous):
                    currSum += prev
                    if currSum < k:
                        continue
                    target = currSum % k
                    ret += seen_remainder[target]
                # now we can safely add
                for _ in range(count_continuous):
                    old_currSum += prev
                    seen_remainder[old_currSum%k] += 1
                count_continuous = 1
            i += 1
        return ret
                
                




