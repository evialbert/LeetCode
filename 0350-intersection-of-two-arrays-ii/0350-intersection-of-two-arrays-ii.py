class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        l = []
        a = Counter(nums1)
        b = Counter(nums2)
        for i,j in a.items():
            if i in b:
                l+=[i]*min(j,b[i])
        return l
