class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int c=0;
      for(int i=0;i<costs.length;i++){
            if(costs[i]<=coins){
                coins-=costs[i];
                c++;            }
            else
                break;
        }
        return c;
    }
}