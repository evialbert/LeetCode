class Solution:
    def isTrionic(self, nums: List[int], k: int = 3) -> bool:
        # At beginning nums should be increasing
        if nums[0] >= nums[1]:
            return False

        n = len(nums)

        sign, switches = 1, 0
        for i in range(1, n):
            delta = nums[i] - nums[i - 1]
            if delta == 0:  # Delta should be always decreasing or increasing
                return False
            elif delta * sign < 0:  # Switch point detected
                sign *= -1
                switches += 1

        return switches == k - 1