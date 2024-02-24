class Solution {
    public int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int[] arr = new int[1000001];
        int ans = 1;
        
        for(int i : nums){
            int prev1 = arr[i-1];
            int prev2 = arr[i];
            ans = Math.max(prev1+1,Math.max(prev2+1,ans));
            //System.out.println(i+" "+ans);
            arr[i] = Math.max(arr[i],prev1+1);
            arr[i+1] = Math.max(prev2+1,arr[i+1]);
        }
        return ans;
    }
}