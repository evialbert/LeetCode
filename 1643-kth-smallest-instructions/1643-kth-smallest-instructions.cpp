class Solution {
public:
    int x, y;
    string res;
    bool q;
    int cnt[16][16];
    void dfs(int i, int j, int& k, string &s){
        if (q) return;
        if (k>cnt[i][j]){
            k-=cnt[i][j];
            return;
        }
        if (i==x && j==y){
                q=true;
                res=s;
        }
        if (j<y){
            s.push_back('H');
            dfs(i, j+1, k, s);
            s.pop_back();
        }
        if (i<x){
            s.push_back('V');
            dfs(i+1, j, k, s);
            s.pop_back();
        }
        return;
    }
    
    string kthSmallestPath(vector<int>& destination, int k) {
        
        x=destination[0], y=destination[1];
        int tmp;
        for (int i=x; i>-1; --i){
            for (int j=y; j>-1; --j){
                tmp=0;
                if (i<15) tmp+=cnt[i+1][j];
                if (j<15) tmp+=cnt[i][j+1];
                tmp=max(1, tmp);
                cnt[i][j]=tmp;
            }
        }
        
        
        string s="";
        q=false;
        dfs(0, 0, k, s);
        return res;
    }
};