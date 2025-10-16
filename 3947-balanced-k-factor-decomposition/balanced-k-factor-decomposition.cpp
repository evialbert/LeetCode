class Solution {
public:
    vector<int> primeFactors(int n) {
    vector<int> factors;      
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) factors.push_back(n);
    return factors;
}
    int gap(vector<int> &v1){
        sort(v1.begin(),v1.end());int n = v1.size();
        return v1[n-1]-v1[0];
    }
    
    map<vector<int>,int> vis;
    int mini =INT_MAX;
    vector<int> ans;
    void dfs(int i , vector<int> &v ,vector<int> v1 , int n ,int k  ){
        if(i==n){
            int diff = gap(v1);
            if(diff<mini){ans=v1;mini=diff;}
            return ;
        }
            for(int j =0;j<k;j++){
                v1[j]*=v[i];
        if(vis[v1]==0){
                vis[v1]=1;
                dfs(i+1,v,v1,n,k);
                // vis[v1]=0;
            }
                v1[j]=v1[j]/v[i];
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int> ans1(k,1);
        ans=ans1;
       vector<int> v=primeFactors(n);
        vector<int> v1(k,1);
        dfs(0,v,v1,v.size(),k);
        return ans;
    }
};