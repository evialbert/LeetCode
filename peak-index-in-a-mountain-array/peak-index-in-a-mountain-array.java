class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int start = 0, end = A.length-1;
        while (start+2 < end) {
            int mid = start+(end-start)/2;
            if (mid-1 >= start && mid+1 <= end && A[mid-1] < A[mid] && A[mid] > A[mid+1]) {
                return mid;
            } else if (mid-1 >= start && mid+1 <= end && A[mid-1] < A[mid] && A[mid] < A[mid+1]) {
                start = mid;
            } else if (mid-1 >= start && mid+1 <= end && A[mid-1] > A[mid] && A[mid] > A[mid+1]) {
                end = mid;
            } else {
                break;
            }
        }
        return start+1;
    }
}