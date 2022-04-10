class Solution {
    public int waysToMakeFair(int[] nums) {
        int odd = 0, even = 0, ans = 0;
		// remove first index 
        for(int i = 1;i<nums.length;i++){
            if(i%2==0){
                even+=nums[i];
            }else{
                odd+=nums[i];
            }
        }
        if(odd==even){
            ans++;
        }
        int pre = 0;
		// check for other index 1........nums.length-1
        for(int i = 1;i<nums.length;i++){
            if(i%2==0){
                even-=nums[i];
                even+=nums[pre];
                
            }else{
                odd-=nums[i];
                odd+=nums[pre];
            }
            if(odd==even){
                ans++;
            }
            pre = i;
        }
        
        return ans;
        
    }
   
}