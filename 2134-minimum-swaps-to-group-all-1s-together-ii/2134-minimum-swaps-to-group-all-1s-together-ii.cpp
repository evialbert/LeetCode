class Solution {
public:
    int minSwaps(vector<int>& oky) 
    {
        vector<int> nums = oky;
        int oneCount = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            oneCount += nums[i];
            nums.push_back(oky[i]);
        }

        int ans = INT_MAX, i = 0, j = 0, windowOneCount = 0 ;
        while(j < oneCount)
            windowOneCount += nums[j++];
        ans = min(ans, oneCount - windowOneCount);

        while(j < n + n)
        {
            if(nums[j++]) windowOneCount++;
            if(nums[i++]) windowOneCount--;
            ans = min(ans, oneCount - windowOneCount);
        }
        return ans;
    }
};