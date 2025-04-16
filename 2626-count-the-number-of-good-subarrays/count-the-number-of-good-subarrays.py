class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        freq = defaultdict(int)
        good_pairs = 0
        left = 0
        total_subarr = 0

        for right in range(len(nums)):
            good_pairs += freq[nums[right]]
            freq[nums[right]] += 1

            # if good_pairs >= k then shrink the window
            while good_pairs >= k:
                freq[nums[left]] -= 1
                good_pairs -= freq[nums[left]]
                left += 1

            # valid subarrays 
            total_subarr += left

        return total_subarr