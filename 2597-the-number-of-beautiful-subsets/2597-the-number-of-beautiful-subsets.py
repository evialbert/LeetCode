class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        nums.sort()
        seen = collections.defaultdict(int)
        self.res = 0
        def backTracking(i, seen, last):
            if len(seen) > 1 and last - k in seen:
                return
            if seen:
                self.res += 1
            for j in range(i, len(nums)):
                seen[nums[j]] += 1
                backTracking(j + 1, seen, nums[j])
                seen[nums[j]] -= 1
                if seen[nums[j]] == 0:
                    del seen[nums[j]]
        backTracking(0, seen, 0)
        return self.res