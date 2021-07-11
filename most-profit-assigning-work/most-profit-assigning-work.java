class Solution {
public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
    int ans=0;
    for(int j:worker){
            int maxx=0;
           for(int k=0;k<difficulty.length;k++){
                if(j>=difficulty[k])
                    maxx=Math.max(maxx,profit[k]);
           }
            ans+=maxx;
    }
    return ans;
}
}