class Solution {
    public long smallestNumber(long num) {
        if(num >= -9 && num<= 9) {return num;}
      
        int digits[] = new int [10];
        long numCopy = Math.abs(num);
        long ans = 0;
      
        while(numCopy > 0) {
          int index = (int)(numCopy % 10);
          digits[index] = digits[index]+1;
          numCopy = numCopy/10;
        }
      
        if(num > 0) {
          for(int i = 1; i < 10; i++) {
            while(digits[i] > 0) {
              ans = ans*10 + i;
              while(digits[0] > 0) {
                ans = ans*10;
                digits[0]--;
              }
             digits[i]--;
            }
          }
        }
      
        else {
          for(int i = 9; i >= 0; i--) {
             while(digits[i] > 0) {
               ans = ans*10 + i;
               digits[i]--;
             }
          }
          ans = -ans;
        }
        return ans;
    }
}