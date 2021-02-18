class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        result = nums[0]+nums[1] +nums[2]
        res = 10000000
        for i in range(len(nums) - 2):
            if i > 0 and nums[i-1] == nums[i]:
                continue
            j = i+1
            k = len(nums) - 1
            while k>j:
                temp = nums[i] + nums[j] + nums[k]
                if temp > target:
                    if temp-target < abs(res - target):
                        res = temp
                    k -= 1
                elif temp < target:
                    if target - temp < abs(res - target):
                        res = temp
                    j += 1
                else:
                    return target
            if abs(res - target) < abs(result - target):
                result = res
        return result