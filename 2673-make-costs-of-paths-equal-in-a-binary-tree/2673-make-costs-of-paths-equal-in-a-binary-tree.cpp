class Solution {
public:
    // To store the answer
    int ans=0;
    
    // A post-order dfs to calculate difference of every left and right path cost
    int dfs(int node, int n,vector<int>& cost){

        // if this node doesn't exist(if it is greater that n) then return 0
        if(node>n)return 0;
        int left=0,right=0;

        // the left path cost
        left=dfs(2*node,n,cost);
        //the right path cost
        right=dfs((node*2)+1,n,cost);

        // we store the difference needed to make the left and right path equal
        ans+= abs(right-left);

        // return the current path
        return cost[node-1] + max(left,right);
    }
    
    int minIncrements(int n, vector<int>& cost) {
        dfs(1,n,cost);
        return ans;
    }
};