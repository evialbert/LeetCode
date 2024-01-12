class Solution:
    def maximumSetSize(self, nums1: List[int], nums2: List[int]) -> int:
        s1, s2 = set(nums1), set(nums2)
        n, n1, n2, c = len(nums1), len(s1), len(s2), len(s1 & s2)
        return min(n, min(n1 - c, n // 2) + min(n2 - c, n // 2) + c)