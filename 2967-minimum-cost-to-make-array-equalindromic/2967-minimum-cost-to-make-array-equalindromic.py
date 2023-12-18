class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        
        nums = sorted(nums)
        
        def isPalindrome(num):
            str_num = str(num)
            i, j = 0, len(str_num)-1
            while i < j:
                if str_num[i] != str_num[j]:
                    return False
                i, j = i+1, j-1
            return True
        
        median = nums[len(nums)//2]
        lower_pal, higher_pal = median, median
        while lower_pal > 0:
            if isPalindrome(lower_pal):
                break
            lower_pal-=1
            
        while higher_pal < 10e19:
            if isPalindrome(higher_pal):
                break
            higher_pal+=1
        
        cost1, cost2 = 0, 0
        for i in range(len(nums)):
            cost1 += abs(nums[i] - lower_pal)
            cost2 += abs(nums[i] - higher_pal)
            
        return min(cost1, cost2)