class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int val=1;
        int start=0;
        bool firstNegative=false;
        int firstNegative_idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                val=1;
                start=i+1;
                firstNegative=false;
                continue;
            }
            
            if(nums[i]<0 and !firstNegative){
                firstNegative=true;
                firstNegative_idx=i;
            }
            
            if(nums[i]<0){
                val*=-1;
            }

            if(val>0){
                res=max(res,i-start+1);
            }else if(val<0 and firstNegative==true){
                res=max(res,i-firstNegative_idx);
            }
            
        }
        
        return res;
    }
};