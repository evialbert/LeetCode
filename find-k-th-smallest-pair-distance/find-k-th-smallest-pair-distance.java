class Solution {
    int solve(int[] nums,int mid) {
        int j=0,cnt=0;
        for(int i=0;i<nums.length;i++) {
            // j=0;
            while(j<nums.length && (nums[j]-nums[i])<=mid) {
                j++;
            }
            cnt+=(j-i-1);
        }
        return cnt;
    }
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int l=0,r=nums[nums.length-1]-nums[0];
        while(l<r) {
            int mid = (l+r)/2;
            int val = solve(nums,mid);
            if(val<k) l=mid+1;
            else r = mid;
        }
        return l;
    }
}