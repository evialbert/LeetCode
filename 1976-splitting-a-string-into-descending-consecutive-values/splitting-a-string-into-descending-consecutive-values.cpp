class Solution {
public:
    bool solve(__int128 p,int cnt,int i,string &s){
        if(i==s.size()){
            if(p==-1||cnt<2){
                return false;
            }
            return true;
        }
        bool ans=false;
        for(int j=i;j<s.size();j++){
            int k=j,l=0;
            __int128 val=0;
            while(k>=i){
                int rem=s[k--]-'0';
                val=rem*pow(10,l++)+val;
            }
            if((p==-1)||(val<p&&(p-val)==1)){
                ans|=solve(val,cnt+1,j+1,s);
            }
        }
        return ans;
    }
    bool splitString(string s) {
        __int128 p=-1;
        return solve(p,0,0,s);
    }
};