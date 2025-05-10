class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        s1=sum(nums1)
        s2=sum(nums2)
        z1=0
        for i in nums1:
            if i==0:
                z1+=1
        z2=0
        for i in nums2:
            if i==0:
                z2+=1
        s1=s1+z1
        s2=s2+z2
        if s1>s2 and z2<1:
            return -1
        if s2>s1 and z1<1:
            return -1
        return max(s1,s2)