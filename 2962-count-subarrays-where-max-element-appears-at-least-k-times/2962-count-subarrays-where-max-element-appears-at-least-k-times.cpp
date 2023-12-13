class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n=*max_element(nums.begin(),nums.end());
        
       int ct=0,t,j=0,i=0;
        int sz=nums.size();
        while(j<sz)
        {
         if(nums[j]==n)
             ct++;
            while(ct>=k){
                ans+=1;
                t=sz-(j+1);
                ans+=t;
                if(nums[i]==n)
                    ct--;
                i++;
                
            }
            j++;
        }
        
        return ans;
    }
};