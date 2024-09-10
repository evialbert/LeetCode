class Solution {
    public long findMaximumScore(List<Integer> nums) {
        
        long ans=0;

        long a=nums.get(0);
        int index=0;

        for(int i=1;i<nums.size();i++){
            if(i==nums.size()-1){
                ans=ans+(i-index)*a;
                break;
            }
            if(nums.get(i)>a){
                ans=ans+(i-index)*a;
                a=nums.get(i);
                index=i;
            }
        }

        return ans;
    }
}