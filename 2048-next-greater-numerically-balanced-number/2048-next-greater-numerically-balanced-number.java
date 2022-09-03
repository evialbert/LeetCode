class Solution {
      public int nextBeautifulNumber(int n) {
        for (int i = n+1; i <= Integer.MAX_VALUE; i++) {
           if(countDigits(i))
               return i;
        }
        return 0;
    }

    private boolean countDigits(int n) {
        int countDigits[] = new int[10];
        while (n > 0) {
            int digit = n % 10;
            countDigits[digit]+=1;
            if (countDigits[digit] > digit) return false;
            n = n / 10;
        }
        for (int i = 0; i < countDigits.length; i++) {
            if (countDigits[i] != 0 && countDigits[i] != i)
                return false;
        }
        return true;
    }
}