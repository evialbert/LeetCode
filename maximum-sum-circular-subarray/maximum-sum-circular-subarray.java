class Solution {
    
    public int kadensMax(int arr[]){
        int ans = arr[0];
        int curr = arr[0];
        for(int i=1;i<arr.length;i++){
            curr = Math.max(curr+arr[i],arr[i]);
            ans = Math.max(ans,curr);
        }
        return ans;
    }
    
    public int kadensMin(int arr[]){
        int ans = arr[0];
        int curr = arr[0];
        for(int i=1;i<arr.length;i++){
            curr = Math.min(curr+arr[i],arr[i]);
            ans = Math.min(ans,curr);
        }
        return ans;
    }
    
    public int maxSubarraySumCircular(int[] A) {
        if(kadensMax(A)<0) return kadensMax(A);
        int sum = 0;
        for(int i=0;i<A.length;i++) sum+=A[i];
        int max_circular = sum-kadensMin(A);
        return Math.max(kadensMax(A),max_circular);
    }
}