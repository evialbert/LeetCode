class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t < 0:
            return False  # edge case

        buckets = {}
        for i, num in enumerate(nums):
            bucket_key = num // (t + 1)
            if bucket_key in buckets and i - buckets[bucket_key][0] <= k:
                return True
            if bucket_key - 1 in buckets and i - buckets[bucket_key - 1][0] <= k and abs(num - buckets[bucket_key - 1][1]) <= t:
                return True
            if bucket_key + 1 in buckets and i - buckets[bucket_key + 1][0] <= k and abs(num - buckets[bucket_key + 1][1]) <= t:
                return True
            buckets[bucket_key] = (i, num)
        return False