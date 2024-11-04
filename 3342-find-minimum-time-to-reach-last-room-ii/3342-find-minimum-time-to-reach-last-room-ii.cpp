class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mv) {
        int m = mv.size();
        int n = mv[0].size(); 
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>pq;//{{t,len},{x,y}};
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        res[0][0]=0;
        pq.push({{0,2},{0,0}});//2 signify that next coloum will get 1 in addition in time
        int delr[]={-1,0,+1,0};
        int delc[]={0,-1,0,+1};
        while(!pq.empty()){
            int t = pq.top().first.first;
            int len = pq.top().first.second;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            if(x==m-1&&y==n-1){
                return t;
            }
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow = x + delr[i];
                int ncol = y + delc[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n){
                    int newdist ;
                    if(len == 2){
                        newdist = max(t+1,mv[nrow][ncol]+1);
                        if(newdist< res[nrow][ncol]){
                            res[nrow][ncol]=newdist;
                            pq.push({{newdist,1},{nrow,ncol}});
                        } 
                    }else{
                        newdist = max(t+2,mv[nrow][ncol]+2);
                        if(newdist<res[nrow][ncol]){
                            res[nrow][ncol]=newdist;
                            pq.push({{newdist,2},{nrow,ncol}});
                        }
                    }
                }
            }

        }
        return -1;
    }
};