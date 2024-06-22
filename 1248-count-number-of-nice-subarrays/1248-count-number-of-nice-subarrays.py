class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        count_map = defaultdict(int)

        odd_count = 0
        for i in range(len(nums)):
            if nums[i] % 2 == 1:
                odd_count += 1
                nums[i] = odd_count
            count_map[odd_count] += 1

        res = count_map[k]
        for cnt in count_map:
            if (cnt + k) in count_map:
                res += count_map[cnt] * count_map[cnt+k]
        
        return res