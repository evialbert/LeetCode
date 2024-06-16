class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long upper=0,cost=0,i=0;
        while(upper<n){
            if(i<nums.size() and nums[i]<=upper+1){
                upper+=nums[i];
                i+=1;
            }
            else{
                cost+=1;
                upper+=upper+1;
            }
        }
        return cost;
    }
};