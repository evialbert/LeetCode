class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<=nums[nums.size()-1];i++)
        {
            int start=0,end=nums.size()-1;
            int x=-1;
            while(start<=end)
            {
                int mid=(end-start)/2+start;
                if(nums[mid]>=i)
                {
                    x=mid;
                    end=mid-1;
                }
                else
                    start=mid+1;
            }
            if(nums.size()-x==i)
                return i;
        }
        return -1;
    }
};