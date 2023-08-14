class Solution {
public:
    int cntP(int n)
    {
        int cnt = 0;
        if(n%2==0)
        {
            cnt++;
            while(n%2==0)
            n/=2;
        }
        for(int i=3;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                cnt++;
                while(n%i==0)
                n/=i;
            }
        }
        if(n>2)
        cnt++;
        return cnt;
    }
    int mod = 1e9+7;
    long long expo(long long a,long long b)
    {
        long long res = 1;
        while(b)
        {
            if(b&1)
            res = ((res%mod)*(a%mod))%mod;
            b>>=1;
            a = (a*a)%mod;
        }
        return res%mod;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i] = cntP(nums[i]);
        }
        stack<int> st;
        vector<int> prev(n,-1);
        vector<int> next(n,n);
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
            st.push(i);
            else
            {
                while(!st.empty() && vec[st.top()]<vec[i])
                {
                    next[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty())
        st.pop();
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            st.push(i);
            else
            {
                while(st.size()>0 && vec[st.top()]<=vec[i])
                {
                    prev[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        priority_queue<vector<long long>> pq;
        for(int i=0;i<n;i++)
        {
            long long total = (i-prev[i])*(next[i]-i);
            pq.push({nums[i],total});
        }
        long long ans = 1;
        while(!pq.empty() && k>0)
        {
            long long counts = pq.top()[1];
            long long val = pq.top()[0];
            pq.pop();
            if(counts<=k)
            {
                k-=counts;
                ans=((ans%mod)*(expo(val,counts)%mod))%mod;
            }
            else
            {
                ans=((ans%mod)*(expo(val,k)%mod))%mod;
                k = 0;
            }
        }
        return ans;
    }
};