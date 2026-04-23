class Solution {
    public int minCost(int[] nums1, int[] nums2) {
        int n = nums1.length;

        // swapping within the same array is free => sorting is free
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int i = 0;
        int j = 0;
        int movesFrom2To1 = 0;
        int movesFrom1To2 = 0;
        while (i < n || j < n) {
            if (i < n && j < n && nums1[i] == nums2[j]) {
                i++;
                j++;
                continue;
            }
            if (i < n && (j >= n || nums1[i] < nums2[j])) {
                // nums1 has some number that's missing from nums2
                if (i + 1 >= n || nums1[i] != nums1[i + 1]) {
                    // this number does not have a pair we can move
                    return -1;
                }
                movesFrom1To2++;
                i += 2;
            } else {
                // nums2 has some number that's missing from nums2
                if (j + 1 >= n || nums2[j] != nums2[j + 1]) {
                    // this number does not have a pair we can move
                    return -1;
                }
                movesFrom2To1++;
                j += 2;
            }
        }
        if (movesFrom2To1 != movesFrom1To2) {
            return -1;
        }
        return movesFrom2To1;
    }
}