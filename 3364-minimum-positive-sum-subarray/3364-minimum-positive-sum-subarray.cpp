class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int mini=INT_MAX;
        //Checking the loop upto which we can get our answer
        for(int i=0;i<n-l+1;i++){
            int sum=0;
        //Moving upto the maximum window size
            for(int j=i;j<i+r && j<n;j++){
                sum+=nums[j];
                //Checking is our answer is positive and the subarray size lies between l and r(inclusive) & replacing it in our answer if it is minimum
                if(sum>0 && j>=l+i-1)
                    mini=min(sum,mini);
            }
        }
        //return -1 if we don't get any answer
        return mini==INT_MAX?-1:mini;
    }
};