class Solution {
public:
    long long minimumCost(string s) {
        int n=s.length();long long cost=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s[i+1])
                cost+=min(i+1,n-i-1);
        }
        return cost;
    }
};