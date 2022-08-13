class Solution {
    public int firstDayBeenInAllRooms(int[] A) {
        int m = (int)1e9 + 7;
        int[] pre = new int[A.length];
        for (int i = 1; i < A.length; i++){
            pre[i] = (pre[i - 1] + 1 + (pre[i - 1] - pre[A[i - 1]] + m) % m + 1) % m;
        }

        return pre[A.length - 1];
    }
}