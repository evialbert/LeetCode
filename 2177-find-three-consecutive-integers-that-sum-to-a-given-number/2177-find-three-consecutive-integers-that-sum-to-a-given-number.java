class Solution {

    public long[] sumOfThree(long num) {
        if (num % 3 != 0) return new long[0];
        long mid = num / 3;
        return new long[] { mid - 1, mid, mid + 1 };
    }
}