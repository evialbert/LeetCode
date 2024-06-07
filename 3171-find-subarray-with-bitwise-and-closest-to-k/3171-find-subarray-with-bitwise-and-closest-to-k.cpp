class Solution {
    struct cmp{
        bool operator()(int a,int b) const{
            return a>b;
        }
    };
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(32,0);
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int x=nums[i];
            for(int j=0;j<31;j++){
                int z= x&(1ll<<j);
                if(z!=0){
                    temp[j]++;
                }else{
                    temp[j]=0;
                }
            }
            map<int,int,cmp>m;
            for(int i=0;i<31;i++){
                if(temp[i]!=0){
                    m[temp[i]]+=(1ll<<i);
                }
            }
            int u=0;
            int i1=0;
            if(m.begin()->first+i<n){
                ans=min(ans,k);
            }
            for(auto it: m){
                u+=it.second;
                ans=min(ans,abs(k-u));
                if(u>k)break;
            }
        }
        return ans;    
    }
};