class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        num_sort = sorted(nums)
        return list(map(lambda x: sorted(nums).index(x), nums))