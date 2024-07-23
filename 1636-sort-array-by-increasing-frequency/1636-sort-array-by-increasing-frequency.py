class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq_map = Counter(nums)
        
        nums.sort(key=lambda x: (freq_map[x], -x))
        
        return nums