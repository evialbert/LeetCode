class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        out = -float('inf')
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if abs(nums[i] - nums[j]) <= min(nums[i], nums[j]):
                    out = max(out, (nums[i] ^ nums[j]))
        return out