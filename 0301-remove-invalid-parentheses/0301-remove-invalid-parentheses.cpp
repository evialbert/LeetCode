class Solution {
public:
    vector<string> ans;
    map<string,bool> mp;
    void rec(string s,string t,int i,int l,int r,int lc, int rc,int lr,int rr){
        if(i==s.length()){
            if(l==r && mp.find(t)==mp.end()){
                ans.push_back(t);
                mp[t] = true;
            }
            return;
        }
        if(l>10){
            return;
        }
        if(lc>lr || rc>rr){
            return;
        }
        if(s[i]!='(' && s[i]!=')'){
            rec(s,t+s[i],i+1,l,r,lc,rc,lr,rr);
            return;
        }
        if(s[i]=='('){
            if(lc==0){
                rec(s,t+s[i],i+1,l+1,r,lc,rc,lr-1,rr);
            }
            else {
                rec(s,t+s[i],i+1,l+1,r,lc,rc,lr-1,rr);
                rec(s,t,i+1,l,r,lc-1,rc,lr-1,rr);
            }
        }
        else {
            if(rc==0){
                if(l==r){
                    return;
                }
                rec(s,t+s[i],i+1,l,r+1,lc,rc,lr,rr-1);
            }
            else {
                if(l==r){
                    rec(s,t,i+1,l,r,lc,rc-1,lr,rr-1);
                    return;
                }
                rec(s,t+s[i],i+1,l,r+1,lc,rc,lr,rr-1);
                rec(s,t,i+1,l,r,lc,rc-1,lr,rr-1);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int l=0,r=0,lr=0,rr=0;
        for(auto st :s){
            if(st=='('){
                l++;
                lr++;
            }
            else if(st==')'){
                rr++;
                if(l==0){
                    r++;
                }
                else {
                    l--;
                }
            }
        }
        if(l==0 && r==0){
            ans.push_back(s);
            return ans;
        }
        rec(s,"",0,0,0,l,r,lr,rr);
        return ans;
    }
};