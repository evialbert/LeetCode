class Solution {
public:

    using ll = long long;
    ll dp[16][2];
    bool check(int x,int carry,string &n){
        if(x==n.size()){
            return carry == 0;
        }
        bool zero = false;
        bool pos = true;
        for(int i=x; i<n.size(); i++){
            int cur = n[i]-'0';
            if(carry==-1 && cur==0){
                cur = 9;
            }
            else{
                cur += carry;
                carry = 0;
            }
            if(zero && cur>0){
                pos = false;
                break;
            }
            if(cur == 0) zero = true;
        }
        return pos;
    }


    long long rec(int i,int carry,string &n){
        if(i == n.size()){
            return carry==0;
        }
        ll &res = dp[i][carry+1];
        if(res!=-1) return res;
        res = 0;
        int req = n[i]-'0';
        if(carry==-1){
            if(req == 0) req = 9;
            else req += carry,carry = 0;
        }

        if(i == n.size()-1 && req==0){
            return res=1;
        }

        // adding contribution of terminating a number either a or b;
        if(i>0 && req>0 && check(i+1,carry,n)) res += 2;
            
        for(int a=1; a<=9; a++){
            for(int b=1; b<=9; b++){
                if((a+b)%10 == req){
                    long long x;
                    if(req!=9) x = rec(i+1,-(a+b)/10,n);
                    else x = rec(i+1,carry,n);
                    res += x;
                }
            }
        }
        return res;
    }
    
    long long countNoZeroPairs(long long x){
        memset(dp,-1,sizeof(dp));
        string n = to_string(x);
        reverse(n.begin(),n.end());
        return rec(0,0,n);
    }
};