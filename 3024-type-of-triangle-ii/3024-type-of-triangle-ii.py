class Solution:
    def triangleType(self, nums: List[int]) -> str:
        a,b,c=nums[0],nums[1],nums[2]
        if a+b>c and b+c>a and a+c>b:
            if a==b==c:  
                return 'equilateral'
            elif a==b!=c or a==c!=b or a!=b==c:
                return 'isosceles'
            else:
                return 'scalene'
        return 'none' 