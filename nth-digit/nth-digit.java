class Solution {
  public int findNthDigit(int n) {
        // Get the number of digits
        int digits = 1;
        
        // The interval size of current digit
        long interval = digits * 9 * (long) Math.pow(10, digits - 1);
        
        int start = 1;
        
        while (n > interval){
            n -= interval;
            start += interval / digits;
            digits++;
            interval = digits * 9 * (long) Math.pow(10, digits - 1);
        }
        
        // The number we should get the digit from
        start += (n - 1) / digits;
        
        // How many times we need to divide to get the digit
        int time = digits - 1 - (n - 1) % digits;
        
        for (int i = 0; i < time; i++){
            start /= 10;
        }
        return start % 10;
    }
}