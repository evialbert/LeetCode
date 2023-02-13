class Solution {

    private:
        int helper(int n,vector<int> &v)
        {
            if(n== 0 || n==1 )return v[n];
            if(v[n]==-1)
            {
                int count{0};
            for(int i{0};i<n;i++)
            {
                int left = i;
                int right = n-1-i;
                count+=helper(left,v) * helper(right,v);
                v[n] = count;
            }
            }
            return v[n];
        }
    public:
    int numTrees(int n) {
        vector<int> v(n+1,-1);
        v[0]= 1;
        v[1] = 1;
        return helper(n,v);
        
    }
};