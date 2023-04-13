class Solution {
public:
    bool pos(int x,vector<int>&nums){
        int n=nums.size();
        int i=0;
        int j=x;
        while(i<x&&j<n){
            if(nums[i]*2<=nums[j])
                i++;
            j++;
        }
        return i==x;
    }
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=nums.size()/2;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(pos(mid,nums)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans*2;
    }
};