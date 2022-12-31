class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int arr[4]  = {1,-1,0,0};
        int brr[4] = {0,0,-1,1};
        int r = grid.size();
        int c = grid[0].size();
      priority_queue< pair<int,pair<int,int>>, vector<  pair<int,pair<int,int>>>, greater<>>pq;
       
        pq.push({0,{0,0}});
        grid[0][0]= -1;
        while(pq.size()>0)
        {
            auto it = pq.top();
            pq.pop();
            int an = it.first;
            int x  =it.second.first;
            int y  = it.second.second;
             if(x==r-1 && y==c-1)
                        return an;
                
            for(int  i = 0;i<4;i++)
            {
                int xx = x + arr[i];
                int yy = y  + brr[i];
                if(xx>=0 && xx<r && yy>=0 && yy<c && grid[xx][yy]!=-1)
                {
                    if(xx==r-1 && yy==c-1)
                        return an;
                    
                    if(grid[xx][yy]==0)
                    {
                        pq.push({an,{xx,yy}});
                    }
                    else if(grid[xx][yy]==1)
                    {
                        pq.push({an+1, {xx,yy}});
                    }
                    grid[xx][yy] = -1;
                    
                }
            }
           
        }
        return -1;
       
    }
};