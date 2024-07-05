class Solution {
public:
    int chk(vector<vector<int>>& g,int si,int n,int sj,int m){
        int x = si;
        int y = n;
        int a = sj;
        int b = m;
        for(int i = si;i<n;i++){
            for(int j = sj;j<m;j++){
                if(g[i][j]){
                    x = max(i,x);
                    y = min(i,y);
                    a = max(j,a);
                    b = min(j,b);
                }
            }
        }
        return (x-y+1)*(a-b+1);
    }
    int minimumSum(vector<vector<int>>& g) {   
        int n = g.size();
        int m = g[0].size();
        int ans = INT_MAX;
        for(int i = 1;i<n;i++){
            for(int j = i+1;j<n;j++){
                int u = chk(g,0,i,0,m);
                int v = chk(g,i,j,0,m);
                int w = chk(g,j,n,0,m);
                ans = min(ans,u+v+w);
            }
            for(int j = 1;j<m;j++){
                int u = chk(g,0,i,0,j);
                int v = chk(g,i,n,0,j);
                int w = chk(g,0,n,j,m);
                ans = min(ans,u+v+w);
                u = chk(g,0,i,j,m);
                v = chk(g,i,n,j,m);
                w = chk(g,0,n,0,j);
                ans = min(ans,u+v+w);
            }
        }
        for(int i = 1;i<m;i++){
            for(int j = i+1;j<m;j++){
                int u = chk(g,0,n,0,i);
                int v = chk(g,0,n,i,j);
                int w = chk(g,0,n,j,m);
                ans = min(ans,u+v+w);
            }
            for(int j = 1;j<n;j++){
                int u = chk(g,0,j,0,i);
                int v = chk(g,0,j,i,m);
                int w = chk(g,j,n,0,m);
                ans = min(ans,u+v+w);
                u = chk(g,j,n,0,i);
                v = chk(g,j,n,i,m);
                w = chk(g,0,j,0,m);
                ans = min(ans,u+v+w);
            }
        }

        return ans;
        
    }
};