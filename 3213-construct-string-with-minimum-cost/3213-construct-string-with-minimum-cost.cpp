
int mod=1000000007;
int inv=190839696;
int base=131;
long long hashValue(int n,string &s){
    long long power=base;
    long long ans=s[0];
    for(int i=1;i<n;i++){
        ans=(ans+power*s[i])%mod;
        power=(power*base)%mod;
    }
    return ans;
}
vector<long long> hashPrefix(int n,string &s){
    long long power=base;
    vector<long long> ans(n,s[0]);
    for(int i=1;i<n;i++){
        ans[i]=(ans[i-1]+power*s[i])%mod;
        power=(power*base)%mod;
    }
    return ans;
}
vector<long long> invPower(int n){
    vector<long long> ans(n,1);
    for(int i=1;i<n;i++){
        ans[i]=(ans[i-1]*inv)%mod;
    }
    return ans;
}
long long subarray(vector<long long> &hash,vector<long long> &inve,int start,int end){
    return ((hash[end]-(start?hash[start-1]:0)+mod)*inve[start])%mod;
}
class Solution {
public:
    int minimumCost(string &target, vector<string> &words, vector<int> &costs) {
        unordered_map<long long,int> cost;
        for(int i=0;i<words.size();i++){
            long long hash=hashValue((int)words[i].size(),words[i]);
            cost[hash]=min((cost.count(hash)?cost[hash]:mod),costs[i]);
        }
        vector<int> len;
        for(int i=0;i<words.size();i++){
            len.push_back((int)words[i].size());
        }
        sort(len.begin(),len.end());
        len.resize(unique(len.begin(),len.end())-len.begin());
        int n=target.size();
        vector<long long> hash=hashPrefix(n,target);
        vector<long long> inve=invPower(n);
        vector<int> dp(n,mod);
        for(int i=0;i<n;i++){
            for(auto l:len){
                if(i-l+1<0) break;
                long long val=subarray(hash,inve,i-l+1,i);
                if(cost.count(val)){
                    int prev=(i-l+1==0?0:dp[i-l]);
                    int curr=cost[val];
                    dp[i]=min(dp[i],prev+curr);
                }
            }
        }
        return (dp[n-1]==mod?-1:dp[n-1]);
    }
};