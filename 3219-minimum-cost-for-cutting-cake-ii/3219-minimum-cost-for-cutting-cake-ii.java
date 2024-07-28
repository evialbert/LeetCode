class Solution {
    public long minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        Arrays.sort(horizontalCut);
        Arrays.sort(verticalCut);
        
        long cost = 0;
        int i=horizontalCut.length-1, j=verticalCut.length-1;
        int hCuts = 1, vCuts = 1;
        
        while(i>=0 && j>=0){
            if(horizontalCut[i] > verticalCut[j]){
                cost += horizontalCut[i] * vCuts;
                hCuts++; i--;
            }
            else{
                cost += verticalCut[j] * hCuts;
                vCuts++; j--;
            }
        }
        while(i>=0){
            cost += horizontalCut[i] * vCuts;
            i--;
        }
        while(j>=0){
            cost += verticalCut[j] * hCuts;
            j--;
        }
        return cost;
    }
}