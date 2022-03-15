class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int l = nums.length , curr =0 , j =0;

        //Base Condition
        if(l == 0) return 0;
        if(l == 1) return (nums[0] >=1) ? 1 : -1;
   
        
        for(int i =0 ;i <= l; i++){
            if(i < nums[j]){
                if( (l - j) == i){
                    return i;
                }
            }
            else if(i == nums[j]){
                if((l-j) == i){
                    return i;
                }
                while( j < l && nums[j] <= i)
                    j++;
                if(j >= l)  return -1;
            }
            else    j++;
        }
        return -1; 
    }
}