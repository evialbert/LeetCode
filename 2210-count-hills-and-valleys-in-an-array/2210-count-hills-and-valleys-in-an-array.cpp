class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        int n = nums.size();
        int res=0;
        
        
        for(int i=1;i<n-1;i++)
        {
            //removing duplicates
            if(nums[i]==nums[i-1]) continue;
            
            int left = i-1;
            int right = i+1;
            
            // finding unique number to the left
            while(left>0 && nums[left]==nums[i])
                left--;
            
            // finding unique number to the right
            while(right<n-1 && nums[right]==nums[i])
                right++;
            
            //hill
            if(nums[left] < nums[i] && nums[right] < nums[i])
                res++;
            //valley
            else if(nums[left] > nums[i] && nums[right] > nums[i])
                res++;
            
        }
        
         return res;
    }
};