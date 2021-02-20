class Solution {
   public int countPrimes(int n) {
        boolean[] iscomp = new boolean[n];
        for (int i = 2; i*i < n; i ++){
            for (int j = 2; i*j < n; j ++){
                iscomp[i*j] = true;
            }
        }
        //count prime
        int count = 0;
        for (int i = 2; i < n; i ++){
            if (iscomp[i] == false)
                count ++;
        }
        return count;
    }

}