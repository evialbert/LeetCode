class Solution {
    public int maxScoreSightseeingPair(int[] values) {
    int max=0;
  
    for(int i=1;i<values.length;i++) {
        
    max=Math.max(max,values[i-1]+values[i]-i);
    values[i]=Math.max(values[i-1],values[i]+i);
    }

    return max;
    }
}