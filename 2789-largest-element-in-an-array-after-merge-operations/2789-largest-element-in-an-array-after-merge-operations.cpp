class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans=0;
      
        vector<long long> arr;
        
    
        int size=nums.size();
        
        for(int i=0;i<size;i++)
        {
            arr.push_back(nums[i]);
            
        }
        
       for(int i=arr.size()-1;i>0;i--)
       {
          if(arr[i-1] <= arr[i])
          {
              arr[i-1] = arr[i] + arr[i-1];
              
          }
       }
        
       return *max_element(arr.begin(),arr.end());
    }
};