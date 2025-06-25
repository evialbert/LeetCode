class Solution {
    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        int pivot1 = findFirstZero(nums1);
        int pivot2 = findFirstZero(nums2);
        int n1 = nums1.length, n2 = nums2.length;
        int[] pos1 = Arrays.copyOfRange(nums1, pivot1, n1);
        int[] pos2 = Arrays.copyOfRange(nums2, pivot2, n2);
        int[] neg1 = negativeCopy(nums1, pivot1);
        int[] neg2 = negativeCopy(nums2, pivot2);


        int negCount = neg1.length * pos2.length + pos1.length * neg2.length;
        long s = 1l;
        if(k > negCount) {
            k -= negCount;
            s = 1l;
        } else {
            int[] temp = neg2;
            neg2 = pos2;
            pos2 = temp;
            s = -1l;
            k = negCount - k +1;
        }

        long start = 0, end = (long)Math.pow(10, 10);

        while(start < end) {
            long mid = start +(end-start)/2;
            if((count(neg1, neg2, mid) + count(pos1, pos2, mid) )>= k) {
                end = mid;
            } else {
                start = mid+1;
            }
        }

        return start * s;
    }

    long count(int[] n1, int[] n2, long max) {
        long count =0;
        int j = n2.length-1;
        for(int i = 0; i < n1.length; i++) {
            while(j >= 0 && ((long)n1[i] * (long)n2[j]) > max) {
                j-=1;
            }
            count += j+1;
        }

        return count;
    }

    private int findFirstZero(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private int[] negativeCopy(int[] nums, int len) {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = -1 * nums[len - 1 - i];
        }
        return res;
    }
}