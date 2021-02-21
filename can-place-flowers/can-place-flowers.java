public class Solution {
    public boolean canPlaceFlowers(int[] bed, int n) {
        for (int i = 0; i < bed.length; i++) {
            if (bed[i] == 0 && (i == 0 || bed[i - 1] == 0) && (i == bed.length - 1 || bed[i + 1] == 0)) {
                bed[i] = 1;
                n--;
            }
        }
        return n <= 0;        
    }
}