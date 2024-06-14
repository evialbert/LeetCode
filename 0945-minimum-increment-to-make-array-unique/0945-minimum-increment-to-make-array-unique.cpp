class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> v;
        bool a[101000]={0};
        for(auto &i:nums){
            if(a[i])v.push_back(i);
            else a[i]=1;
        }
        sort(v.begin(),v.end());
        int i=1,n=v.size(),ans=0;
        for(int j=0;j<n;++j){
            while((a[i] || i<=v[j]))i++;
            ans+=i-v[j];
            a[i]=1;
        }
        return ans;
    }
};