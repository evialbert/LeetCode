class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        arr1, arr2 = 0, 0
        nums1.sort()
        nums2.sort()

        m, n = len(nums1), len(nums2)
        uniques = set()

        while arr1 < m and arr2 < n:
            if nums1[arr1] == nums2[arr2]:
                uniques.add(nums1[arr1])
                arr1 += 1
                arr2 += 1
            elif nums1[arr1] < nums2[arr2]:
                arr1 += 1
            else:
                arr2 += 1
        return uniques     