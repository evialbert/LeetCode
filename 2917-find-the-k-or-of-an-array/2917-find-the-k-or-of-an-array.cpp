class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans=0; 
        for(int i=0;i<=31;i++){
           int count=0;
           for(int j=0;j<nums.size();j++){
                if((1<<i) & nums[j]){
                   count++;
                }
           }
           if(count>=k){
              ans+=pow(2,i);
           }
        }
        return ans;
            
    }
};