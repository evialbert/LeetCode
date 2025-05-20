class Solution {
public:
    int minMoves(vector<string>& matrix) {
        // simple bfs but this portal thing is a twist
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        unordered_map<char,vector<pair<int,int>>>mp;
        vector<bool>used(26,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isupper(matrix[i][j])){
                    mp[matrix[i][j]].push_back({i,j});
                }
            }
        }
        using T = tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>> pq;
        vector<int>dx={0,1,0,-1};
        vector<int>dy={1,0,-1,0};
        // i,j
        pq.push({0,0,0});
        dist[0][0]=0;
        int ans=INT_MAX;
        while(!pq.empty()){
            auto [steps,i,j]=pq.top();
            pq.pop();
            if(i==m-1 && j==n-1){
                return steps;
            }
            if(steps>dist[i][j]){
                continue;
            }

            char c=matrix[i][j];
            if(isupper(c) && !used[c-'A']){
                used[c-'A']=true;
                for(auto &[x,y]:mp[c]){
                    if(steps<dist[x][y]){
                        dist[x][y]=steps;
                        pq.push({steps,x,y});
                    }
                }
            }
            
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];

                if(ni>=0 && nj>=0 && ni<m && nj<n && matrix[ni][nj]!='#'){
                    if(steps+1<dist[ni][nj]){
                        dist[ni][nj]=steps+1;
                        pq.push({steps+1,ni,nj});
                    }
                }
            }   
        }
        return -1;
    }
};