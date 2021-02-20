public class Solution {
    public boolean isPowerOfFour(int num) {
        if(num < 0)
            return false;
        int tmp = num-1;
        return (num & tmp) == 0 && tmp % 3 == 0;
    }
}