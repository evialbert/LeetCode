class Solution {
    pair<int,int> pos(int x,int n){
        int r=(x-1)/n;
        int c=(x-1)%n;
        if(r&1){
            c=(n-1)-c;
        }
        r=(n-1)-r;
        return{r,c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>dist(n*n+1,-1);
        dist[1]=0;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=x+1;i<=min(x+6,n*n);i++){
                pair<int,int> v=pos(i,n);
                int distination= (board[v.first][v.second])!=-1 ? board[v.first][v.second] : i;
                if(dist[distination]==-1){
                    dist[distination]=dist[x]+1;
                    q.push(distination);
                }
            }
        }
        return dist[n*n];

    }
};