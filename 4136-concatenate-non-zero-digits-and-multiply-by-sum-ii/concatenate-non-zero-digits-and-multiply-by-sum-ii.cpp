class Solution {
public:
    #define ll long long
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod=1e9+7;
        int n=s.size();

        vector <int> nums(n);
        for (int i=0;i<n;i++)nums[i]=s[i]-'0';

        vector <ll> pf(n);
        pf[0]=nums[0];
        vector <ll> calpf(n);
        calpf[0]=nums[0];

        for (int i=1;i<n;i++)pf[i]=pf[i-1]+nums[i];

        for (int i=1;i<n;i++){
            if (nums[i]!=0)calpf[i]=(((calpf[i-1]%mod)*10)%mod+nums[i])%mod;
            else calpf[i]=calpf[i-1]%mod;
        }

        vector <int> ans;

        int m=queries.size();

        vector <ll> ten(n+1);
        ten[0]=1;
        for (int i=1;i<=n;i++)ten[i]=((ten[i-1]%mod)*10)%mod;

        vector <int> zeroes_pf(n,0);
        
        if (nums[0]==0)zeroes_pf[0]=1;
        for (int i=1;i<n;i++){
            if (nums[i]==0)zeroes_pf[i]=zeroes_pf[i-1]+1;
            else zeroes_pf[i]=zeroes_pf[i-1];
        }

        for (int i=0;i<m;i++){
            int st=queries[i][0];
            int end=queries[i][1];
            ll zeroes;

            if (st-1>=0)zeroes=zeroes_pf[end]-zeroes_pf[st-1];
            else zeroes=zeroes_pf[end];

            ll x;

            if (st-1>=0)x=(calpf[end]%mod-((calpf[st-1]%mod)*(ten[end-st+1-zeroes]%mod))%mod+mod)%mod;
            else x=calpf[end]%mod;


            ll sum;
            if (st-1>=0)sum=pf[end]-pf[st-1];
            else sum=pf[end];

            ll an=((x%mod)*(sum%mod))%mod;

            ans.push_back(an); 
        }

        return ans;
    }
};