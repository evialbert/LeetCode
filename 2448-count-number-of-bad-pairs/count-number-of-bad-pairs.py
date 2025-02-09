class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        hT = defaultdict(int)
        
        # Count occurrences of nums[i]-i since nums[i]-i = nums[j]- j
        for i in range(n):
            hT[nums[i]-i] += 1
        
        total_non_bads = 0
        
        # Calculate the number of non-bad pairs
        for count in hT.values():
            if count > 1:
                total_non_bads += count * (count - 1) // 2
        
        # Total pairs - non-bad pairs = bad pairs
        total_pairs = n * (n - 1) // 2
        bad_pairs = total_pairs - total_non_bads
        
        return bad_pairs