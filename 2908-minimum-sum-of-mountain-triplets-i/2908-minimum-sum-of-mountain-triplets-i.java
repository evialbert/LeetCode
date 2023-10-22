class Solution {
    public int minimumSum(int[] n) {
        int ans=1000; //1000 taken just for taking minmun triplet
        for(int i=0;i<n.length;i++){
            for(int j=0;j<n.length;j++){
                for(int k=0;k<n.length;k++){
                    if(i<j && j<k && n[i]<n[j] && n[k]<n[j]){
                        int mx=n[i]+n[j]+n[k];
                        ans=Math.min(mx,ans);
                    }
                }
            }
        }
        if(ans==1000) return -1;
        return ans;
    }
}