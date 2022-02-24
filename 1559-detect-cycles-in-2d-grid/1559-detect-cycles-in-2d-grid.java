class Solution {
    public boolean containsCycle(char[][] grid) {
        int row=grid.length;
        int col=grid[0].length;
        boolean visited[][] = new boolean[row][col];
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!visited[i][j])
                {
                    if(bfs(i,j,-1,-1,grid,visited))
                        return true;
                }
            }
        }
        return false;
    }
    boolean bfs(int i, int j, int previ,int prevj, char grid[][], boolean visited[][])
    {
        int dirs[][]={{0,1},{1,0},{0,-1},{-1,0}};
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(i,j,previ,prevj,grid[i][j]));
        visited[i][j]=true;
        while(!q.isEmpty())
        {
            Node node=q.remove();
            for(int dir[]: dirs)
            {
                int x=node.i+dir[0];
                int y=node.j+dir[1];
                
                if(x<0 || y<0 || x>=grid.length || y>=grid[0].length || grid[x][y]!=node.ch)
                    continue;
                if(visited[x][y])
                {
                    if(!(node.previ==x && node.prevj==y))
                        return true;
                }
                if(!visited[x][y])
                {
                    visited[x][y]=true;
                    q.add(new Node(x,y,node.i,node.j,grid[x][y]));
                }
            }
        }
        return false;
    }
}
class Node
{
    int i,j,previ,prevj;
    char ch;
    Node(int i, int j, int previ,int prevj, char ch)
    {
        this.i=i;
        this.j=j;
        this.previ=previ;
        this.prevj=prevj;
        this.ch=ch;
    }
}