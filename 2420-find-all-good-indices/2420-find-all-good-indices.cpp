class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp1(n,1), dp2(n,1);
        //the edges, no subarrays
        dp1[0]=0;
        dp2[n-1]=0;
        
        //the first element, index 0 is 0 since there is no subarrays; 
        //for index 1, the there is only one element, so must be non-increasing; 
        //start to check from index 2. 
        for (int i=2; i<n; i++){
            if (nums[i-1] <= nums[i-2]){
                dp1[i] = 1+ dp1[i-1];
            }
        }
        
        for (int i=n-3; i>=0; i--){
            if (nums[i+1] <= nums[i+2])
                dp2[i] = dp2[i+1] +1;
        } 
        
        vector<int> res;
        for (int i=0; i<n; i++){
            //both satisfy non increasing and non decreasing
            if (dp1[i] >=k && dp2[i] >= k)
                res.push_back(i);
        }
        return res;
        
       
    }
};