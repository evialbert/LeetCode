class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        int ele = 0;
        for(int i=0;i<n;i++)
        {
            tmp[i] = nums[i];
            if(nums[i]!=1)
            ele++;
        }
        int cnt=0;
        while(tmp.size()>1)
        {
            for(int i=0;i<tmp.size()-1;i++)
            {
                if(__gcd(tmp[i],tmp[i+1])==1)
                return cnt+ele;
                tmp[i] = __gcd(tmp[i],tmp[i+1]);
                if(tmp[i]==1)
                return cnt+ele;
            }
            cnt++;
            tmp.pop_back();
        }
        return -1;
    }
};