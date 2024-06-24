class Solution {
public:
    int minOperations(vector<int>& nums) {
      
        int count=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
               if(i+3>n){
                   return -1;
               }
               for(int j=i;j<i+3;j++){
                   nums[j]=!nums[j];
               } 
                count++;
            }
        }
        return count;
    }
};