class Solution {
   public int timeRequiredToBuy(int[] tickets, int k) {
        int ans=0;
        int val=tickets[k];
        int n=tickets.length;
        for(int i=0;i<n;i++){
            int v=tickets[i];
            if(v<val)
                ans+=v;
           else{
               if(i<=k){
                   ans+=val;
               }else{
                   ans+=val-1;
               }
           }
            
        }
        return ans;
    }
}