class Solution {
    public long maximumHappinessSum(int[] arr, int k) {
        Arrays.sort(arr);
        long sum=0;
        int j=0;
        for(int i=arr.length-1;i>=0 && k>0;i--){
            if(arr[i]-j>0){
                sum+=arr[i]-j;
            }
            j++;k--;
        }
        return sum;
    }
}