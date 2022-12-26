class Solution {
public:
    int md=1e9+7;
    int totalStrength(vector<int>& st) {
        int n=st.size();
        stack<int>s,s1;
        vector<long long> nsl(n,-1),nsr(n,n),pr1(n+2),pr2(n+2),sf1(n+2),sf2(n+2);
        for(int i=0;i<n;i++){
            while(!s.empty() && st[s.top()]>st[i])s.pop();
            if(!s.empty())nsl[i]=s.top();
            s.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s1.empty() && st[s1.top()]>=st[i])s1.pop();
            if(!s1.empty())nsr[i]=s1.top();
            s1.push(i);
        }
        for(int i=1;i<=n;i++){
            pr1[i]=(pr1[i-1]+st[i-1])%md;
            pr2[i]=(pr2[i-1]+pr1[i])%md;
        }
        for(int i=n;i>=1;i--){
            sf1[i]=(sf1[i+1]+st[i-1])%md;
            sf2[i]=(sf2[i+1]+sf1[i])%md;
        }
        auto lsum=[&](int l,int r){
            if(l>r) return 0;
            long d=r-l+1,sub=(d*sf1[r+2])%md;
            long ans=(sf2[l+1]-sf2[r+2]+md)%md;
            ans=(ans-sub+md)%md;
            return (int)ans;            
        };
        auto rsum=[&](int l,int r){
            if(l>r) return 0;
            long d=r-l+1,sub=(d*pr1[l])%md;
            long ans=(pr2[r+1]-pr2[l]+md)%md;
            ans=(ans-sub+md)%md;
            return (int)ans;            
        };
        long ans=0;
        for(int i=0;i<st.size();i++){
            int l=nsl[i]+1,r=nsr[i]-1;
            long curr_min=st[i];
            long right_sum = rsum(i+1,r);
            long left_sum = lsum(l,i);
            long curr_sum = (right_sum*(i-l+1))%md;
            curr_sum = (curr_sum + (left_sum*(r-i+1))%md)%md;
            long curr_ans = (curr_sum*curr_min)%md; 
            ans = (ans+curr_ans)%md;       
        }        
        return ans%md;
    }
};