class Solution {
public:
    int minimumSize(vector<int>& nums, int mo) {
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int mid;
        int ans=INT_MAX;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(fun(nums,mid,mo)==true)
            {
                ans=min(ans,mid);
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
    bool fun(vector<int>&nums,int &mid,int &mo)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mid<=nums[i])
            {
                if(nums[i]%mid==0)
                {
                    c=c+((nums[i]/mid)-1);
                }
                else
                {
                    c=c+((nums[i]/mid));
                }
            }
        }
        if(c<=mo)
        {
            return true;
        }
        return false;
    }
};