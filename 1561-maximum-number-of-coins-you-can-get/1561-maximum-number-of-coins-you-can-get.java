class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        
        int i = 0;
        int j = piles.length - 2;
        
        int total = 0;
        
        while(i < j){
            total += piles[j];
            i++;
            j -= 2;
        }
        
        return total;
    }
}