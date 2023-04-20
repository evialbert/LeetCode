class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ind=0,count=0;
        for(int i=0;i<n;i++){
            auto ub=upper_bound(nums.begin()+ind+1,nums.end(),nums[i]);
            if(ub!=nums.end()){
                count++;
                ind=ub-nums.begin();
            }
            else
                break;
        } 
        return count;
    }
};