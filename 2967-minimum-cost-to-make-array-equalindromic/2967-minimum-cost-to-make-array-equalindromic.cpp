class Solution {
public:
    bool check(int n)
    {
        string temp=to_string(n);
        int str=0;
        int end=temp.size()-1;
        while(str<end)
        {
            if(temp[str]!=temp[end])
            {
                return false;
            }
            str++;
            end--;
        }
        return true;
    }
    int solve_i(int n)
    {
        while(check(n)==false)
        {
            n++;
        }
        return n;
    }
    int solve_d(int n)
    {
        while(check(n)==false)
        {
            n--;
        }
        return n;
    }
    long long cal(int n,vector<int>& nums)
    {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=ans+abs(nums[i]-n);
        }
        return ans;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];
        int first=solve_i(median);
        int second=solve_d(median);
        return min(cal(first,nums),cal(second,nums));
    }
};