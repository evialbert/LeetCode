class Solution {
public:
    #define ll long long

    ll dfs(ll curr,ll par,ll target,vector<int>&nums,vector<ll>adj[],ll &count){
        ll sum=nums[curr];
        for(auto &x:adj[curr]){
            if(x!=par){
                sum+=dfs(x,curr,target,nums,adj,count);
            }
        }
        if(sum==target){
            count--;
            return 0;
        }
        return sum;
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        ll n=nums.size(),total=0;
        for(auto &x:nums){
            total+=x;
        }
        vector<ll>adj[n];
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        set<ll>ss;
        for(ll i=1;i*i<=total;i++){
            if(total%i==0){
                ss.insert(i);ss.insert(total/i);
            }
        }
        for(auto &x:ss){
            if(x==total){
                continue;
            }
            ll count=total/x;
            if(dfs(0,-1,x,nums,adj,count)==0 && count==0){
                return (total/x)-1;
            }
        }
        return 0;
    }
};