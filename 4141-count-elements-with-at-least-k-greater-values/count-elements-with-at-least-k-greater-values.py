class Solution:
    def countElements(self, nums: List[int], k: int) -> int:
        if k == 0:
            return len(nums)
        # the top kth person 
        # so any person below k will have atleast k greater persons
        # but are the k persons strict?
        nums.sort()
        threshold = nums[len(nums)-k]
        ans = 0
        for x in nums:
            #if it is strict then only its valid elmnt
            if threshold > x:
                ans += 1
        return ans