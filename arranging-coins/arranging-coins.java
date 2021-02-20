public class Solution {

    public int arrangeCoins(int n) {

        if(n<0) return -1;

        if(n==0) return 0;

        int rows = 0;

        long sum = 0;

        while(sum<=n){

            sum += rows+1;

            rows++;

        }

        return rows-1;

    }

}