class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        vector<long long> v;
        long long sum=0;
        for(int i=0;i<chalk.size();i++)
        {
            sum+=chalk[i];
            v.push_back(sum);
        }
        int temp=k%sum;
        int ans=upper_bound(v.begin(),v.end(),temp)-v.begin();
        return ans;
    }
};