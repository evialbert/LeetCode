class Solution {
    long long utilfunc(int num,vector<int> &nums,vector<int> &cost)
    {
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += (long long)abs(nums[i] - num)*(long long)cost[i];
        }
        return sum;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = LONG_MAX;
        
        int l = *min_element(nums.begin(),nums.end());
        int h = *max_element(nums.begin(),nums.end());
        
        while(l<=h)
        {
            int mid = (l + (h-l)/2);
            
            long long sum = utilfunc(mid,nums,cost);
            ans = min(ans,sum);
            
            long long sum1 = utilfunc(mid-1,nums,cost);
            long long sum2 = utilfunc(mid+1,nums,cost);
            
            if(sum<=sum1 && sum<=sum2) break;
            if(sum1<sum2)
            {
               ans = min(ans,sum1);
               h = mid-1;
            }else{
                ans = min(ans,sum2);
                l = mid+1;
            }
        }
      return ans;
    }
};