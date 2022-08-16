class Solution {
    public int countKDifference(int[] arr, int k) {
        int count = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i+1; j < arr.length; j++) {
                if (Math.abs(arr[i] - arr[j]) == k) count++;
            }
        }
        return count;
    }
}