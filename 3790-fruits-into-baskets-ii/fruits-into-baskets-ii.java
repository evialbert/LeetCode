class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = baskets.length;
        boolean[] filled = new boolean[n];
        int c = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(!filled[j]  && baskets[j]>=fruits[i]){
                    filled[j] = true;
                    c++;
                    break;
                }
            }
        }
        return n-c;
    }
}