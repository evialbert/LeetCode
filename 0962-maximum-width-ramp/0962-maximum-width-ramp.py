class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack , max_width = [] , 0
        for i in range(len(nums)) :
            if not stack or nums[stack[-1]] > nums[i] :
                stack.append(i)

        for j in range(len(nums)-1 , -1 , -1 ) :
            while stack and nums[j] >= nums[stack[-1]] :
                i = stack.pop()
                max_width = max(max_width , j-i)

        return max_width