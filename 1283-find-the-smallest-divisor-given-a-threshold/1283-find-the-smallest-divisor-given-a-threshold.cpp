class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int l=1;
        int u=*max_element(nums.begin(),nums.end());
        int res=0;
        int n=nums.size();
        while(l<=u)
        {
            int mid=(l+u)/2;
            int temp=0;
            for(int i=0;i<n;i++)
            {
                temp+=ceil(((float)nums[i])/mid);
            }
            if(temp<=threshold)
            {
                res=mid;
                u=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
    }
};