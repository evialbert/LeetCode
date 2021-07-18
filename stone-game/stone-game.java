class Solution {
    public boolean stoneGame(int[] piles) {
     int i=0;
        int j=piles.length-1;
        int sum1=0;
        int sum2=0;
        int c=1;
        while(i!=j+1){
            
            if(piles[i]>piles[j] && c%2!=0){
                sum1+=piles[i];
                i++;
            }
            else if(c%2!=0){
                sum1+=piles[j];
                j--;
            }
            else if(piles[i]<piles[j] && c%2==0){
                sum2+=piles[i];
                i++;
            }
            else{
                sum2+=piles[j];
            j--;
            }
            c++;
        }
if(sum1>sum2){
    return true;
}
        else{
            return false;
        }
}
}