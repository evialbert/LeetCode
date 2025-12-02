class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        bool appended = false;

        long long ans = 0; // for appending one element
        int minOper = INT_MAX; 
        for(int i = 0; i < n; i++){
            // to make the current element of nums1[i] equal to nums2[i] 
            // we need to perform abs(nums1[i] - nums2[i]) operations
            ans += abs(nums1[i] - nums2[i]);
            if(!appended && nums2[n] >= min(nums1[i], nums2[i]) && nums2[n] <= max(nums1[i], nums2[i])){
                // if the last num of nums2 (nums2[n]) lies in between the nums1[i] and nums2[i], 
                // we can just append it at the end of nums[1] during the current operations
                // when, while increasing or decreasing the nums1[i], we reach at nums2[n]

                // we will just need one extra operation to append
                ans++;
                appended = true;
            }else{
                if(appended) continue;
                // if last num of nums2 (nums2[n]) is out of range [nums1[i],nums2[i]), 
                // we can append the nearest num to the end of nums1 and then we can increase it or decrease it
                // to make it equal to the nums2[n]
                minOper = min(minOper, min(abs(nums1[i] - nums2[n]), abs(nums2[i] - nums2[n])));
            }
        }

        return ans + (appended ? 0 : minOper + 1); // +1 for append operation
    }
};