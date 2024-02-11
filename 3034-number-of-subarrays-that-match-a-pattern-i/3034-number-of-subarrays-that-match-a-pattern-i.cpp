class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
             int k=0,j=i;
             bool flag=true;
            while((k<pattern.size())&&(j<nums.size()-1)){
                
                if(pattern[k]==1){
                    cout<<nums[j]<<" "<<nums[j+1]<<" ";
                    if(nums[j]>=nums[j+1]){
                     flag=false;  
                    }       
                }
                else if(pattern[k]==0){
                    
                    if(nums[j]!=nums[j+1]){
                        flag=false;  
                    }
                    
                }
                else if(pattern[k]==-1){
                    if(nums[j]<=nums[j+1]){
                        flag=false;
                    }
                }
                j++;
                k++;     
            }
           
            if(k==pattern.size()&&flag==true)
                ans++;
           
           
        }
        return ans;
    }
};