class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        if nums1[-1] > nums2[-1]:
            nums1, nums2 = nums2, nums1
        max1, max2 = nums1[-1], nums2[-1]
        rs_swap_last_element = 1
        rs = 0
        for i in range(len(nums1) - 1):
            if max(nums1[i], nums2[i]) > max2 or min(nums1[i], nums2[i]) > max1:
                return -1
            elif nums1[i] > max1:
                rs += 1
            elif nums2[i] > max1:
                rs_swap_last_element += 1
        return min(rs, rs_swap_last_element)