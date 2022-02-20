class Solution {
    public int findKthPositive(int[] arr, int k) {
        int ans = 1;
        int i = 0;
        
        while(k>0 && i<arr.length){
            if(arr[i] != ans){
                k--;
            }
            else{
                i++;
            }
            ans++;
        }
        if(i==arr.length)
            return ans+k-1;
        return ans-1;
    }
}