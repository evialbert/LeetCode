class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>v;
       int n=nums.size();
      int i=0,j=n-1;

     while(i<j)
     {
         while(i<j && nums[i]%2==0)
         {
            i++;
         }
        while(i<j && nums[j]%2!=0)
         {
             j--;
         }
         
             swap(nums[i],nums[j]);
     }
       return nums;
    }
};