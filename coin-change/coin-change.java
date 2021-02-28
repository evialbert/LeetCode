//Bottom-Up 

class Solution {
    public int coinChange(int[] coins, int amount) {
        //dp: array signaling how many minimum coins can fit for each amount between 0 <= i <= amount
        //and then the res is minimum coins between all array[amount-coins[i]]
        if (amount == 0) return 0;
        int[] cpa = new int[amount+1]; //cpa = coins per amount
        cpa[0] = 0;
        
        //put 1 in cpa if a single coin fits there
        for (int i=0; i<coins.length; i++) {
            if (coins[i] <= amount) {
                if (coins[i] == amount) return 1;
                cpa[coins[i]] = 1;
            } 
        }
        
        for (int i=0; i < cpa.length; i++) {
            if (cpa[i] == 0) { //if no amount found yet for size i
                //find smallest sum of coins to fill i
                int min = Integer.MAX_VALUE;
                for (int j=coins.length-1; j>=0; j--) { //o(sizeofcoins) = o(12) = o(1)
                    if (coins[j] < i && cpa[i-coins[j]] != 0)  //if wont overflow out of array & sum at spot isnt 0
                            min = Math.min(min, cpa[i-coins[j]]);     
                }
                if (min != Integer.MAX_VALUE) //found sum of coins
                    cpa[i] = min+1;
            }
        }
        if (cpa[cpa.length-1] != 0)
            return cpa[cpa.length-1];
        else return -1;
    }
}