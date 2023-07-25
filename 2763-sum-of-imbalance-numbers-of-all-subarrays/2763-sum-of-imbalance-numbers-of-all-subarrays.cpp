class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            multiset<int> ms;
            ms.insert(nums[i]);
            for(int j=i+1;j<n;j++)
            {
                auto it = ms.upper_bound(nums[j]);
                if(it==ms.end())
                {
                    it--;
                    if(nums[j]-(*it)>1)
                        cnt++;
                }
                else if(it==ms.begin())
                {
                    if((*it)-nums[j]>1)
                        cnt++;
                }
                else
                {
                    int num1 = *it;
                    it--;
                    int num2 = *it;
                    if(num1-num2>1)
                    {
                        cnt--;
                        if(nums[j]-num2>1)
                            cnt++;
                        if(num1-nums[j]>1)
                            cnt++;
                    }
                }
                ms.insert(nums[j]);
                ans+=cnt;
            }
        }
        return ans;
    }
};