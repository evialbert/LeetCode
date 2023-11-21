class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long res = 0;
        for(int i=0;i<nums.size();i++)
        {
            int rev_num = 0,num=nums[i];
            while(num)
            {
                rev_num = 10*rev_num+num%10;
                num = num/10;
            }
            mp[nums[i]-rev_num]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            long long n=it->second;
            if(n>1)
            {
                res =  (res+(n*(n-1)/2))%1000000007;
            }
        }
        return res;
    }
};