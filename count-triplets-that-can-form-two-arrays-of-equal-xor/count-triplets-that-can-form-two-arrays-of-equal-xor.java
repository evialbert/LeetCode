class Solution {
    public int countTriplets(int[] arr) {
        int size = arr.length, ret = 0;
        if (size >= 2) {
            for (int i = 1; i < size; i++) {
                int xorSum = arr[i];
                for (int j = i - 1; j >= 0; j--) {
                    xorSum ^= arr[j];
                    if (xorSum == 0) {
                        ret += i - j;
                    }
                }
            }
        }

        return ret;
    }
}