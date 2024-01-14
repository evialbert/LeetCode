class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
       vector<int>vi,vj,ans;
        int n=s.size(),an=a.size(),bn=b.size();        
        for(int i=0;i<n;i++){
            if(  s.substr(i,an)==a) vi.push_back(i);
            if(  s.substr(i,bn)==b) vj.push_back(i);
        }
        
        for(auto &i:vi){
         
            if(vj.size()==0) break;
            int idx=lower_bound(vj.begin(),vj.end(),max(0,i-k))- vj.begin();
             int idx2=lower_bound(vj.begin(),vj.end(),i+k ) - vj.begin();
            
            if((idx!=vj.size() && abs(vj[idx]-i)<=k)  ||  (idx2!=vj.size() && abs(vj[idx2]-i)<=k) )  ans.push_back(i);
        }
        
       
        
        return ans;
    }
};