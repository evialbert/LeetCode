class Solution {
    public int mergeStones(int[] stones, int k) {
        if(k!=2 && stones.length%(k-1)!=1) return -1;
        int size= stones.length;
        int[] prefixSum= new int[size];
        int[][] memo= new int[size][size];
        prefixSum[0]= stones[0];
        for(int i=1; i<size; i++){
            prefixSum[i]+= prefixSum[i-1]+stones[i];
        }
        return mergeCost(stones,prefixSum,memo,k,0,size-1);
    }
    public int mergeCost(int[] stones,int[] prefixSum,int[][] memo,int k,int left,int right){
        if(right-left+1<k) return 0;
        if(memo[left][right]!=0) return memo[left][right];
        if(right-left+1==k){
            memo[left][right]= left==0? prefixSum[right]:prefixSum[right]-prefixSum[left-1];
            return memo[left][right];
        }
        int ans= Integer.MAX_VALUE;
        for(int i=left; i<right; i+= k-1){
            ans= Math.min(ans,mergeCost(stones,prefixSum,memo,k,left,i)+
                          mergeCost(stones,prefixSum,memo,k,i+1,right));
        }
        if(k==2||(right-left+1)%(k-1)==1){
            ans+= left==0? prefixSum[right]:prefixSum[right]-prefixSum[left-1];
        }
        memo[left][right]+= ans;
        return memo[left][right];
    }
}