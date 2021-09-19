class Solution {
    public int maxSatisfied(int[] c, int[] g, int m) {
        int i=0;
        int j=m-1;
        int presum=0;
        int windowsum=0;
        int postsum=0;
        for(int k=i;k<=j;k++) windowsum+=c[k];
        for(int k=j+1;k<c.length;k++) postsum+=g[k]==0?c[k]:0;
        int max = 0;
        while(j<c.length){
            max=Math.max(max,presum+windowsum+postsum);
            presum+=g[i]==0?c[i]:0;
            if(j<c.length-1){
                windowsum+=c[j+1]-c[i];
                postsum-=g[j+1]==0?c[j+1]:0;
            }
            j++;
            i++;
        }
        return max;
        
    }
}