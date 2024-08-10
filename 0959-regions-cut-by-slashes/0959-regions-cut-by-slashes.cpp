class Solution {
public:
    vector<int>parent;
    int count;
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
        {
            count++;
        }
        else
        {
            parent[x]=y;
        }
    }
    int regionsBySlashes(vector<string>& mat) 
    {    
        int n=mat.size();
         count=1;
        int dot=n+1;
        parent=vector<int>(dot*dot+1,0);
        for(int i=0;i<dot*dot+1;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<dot;i++)
        {
            for(int j=0;j<dot;j++)
            {   
                if(i==0||j==0||i==dot-1||j==dot-1)
                {
                    int cellx=i*dot+j;
                    if(cellx!=0)
                    Union(0,cellx);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]=='/')
                {
                    int x=(i)*dot+j+1;
                    int y=(i+1)*dot+j;
                    Union(x,y);
                
                }
                else if(mat[i][j]=='\\')
                {
                    int x=i*dot+j;
                    int y=(i+1)*dot+(j+1);
                    Union(x,y);
                }
            }
        }
        return count;
    }
};