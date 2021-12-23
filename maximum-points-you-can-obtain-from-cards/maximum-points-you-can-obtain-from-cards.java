class Solution {
    public int maxScore(int[] cardPoints, int k) {
        
        int i=0, j=0;
        int tSum=0;
        int n=cardPoints.length;
        
        for (int points: cardPoints) {
            tSum+=points;
        }
        
        int wSize=n-k;
        int sum=0, min=Integer.MAX_VALUE;
        
        while (j<n) {
            
            sum=sum+cardPoints[j];
            
            if (j-i==wSize-1) {
                
                min=Math.min(min,sum);
                sum=sum-cardPoints[i];
                i++;
            }
            
            j++;
        }
        
        if (min==Integer.MAX_VALUE) {
            min=0;
        }
        
        return tSum-min;
    }
}