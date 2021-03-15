/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        return dfs(grid, 0, 0, rows-1, cols-1);
    }
    public Node dfs(int[][] grid, int i, int j, int m, int n){
        Node node = new Node();
        int base = grid[i][j];
        boolean isLeaf = true;
        for(int x=i; x<=m && isLeaf; x++){
            for(int y=j; y<=n; y++){
                if(base != grid[x][y]){
                    isLeaf = false;
                    break;
                }
            }
        }
        if(isLeaf){
            node.isLeaf = true;
            node.val = base==1;
        }else{
            node.topLeft = dfs(grid, i, j, i+(m-i)/2, j+(n-j)/2);
            node.topRight = dfs(grid, i, j+(n-j)/2+1, i+(m-i)/2, n);
            node.bottomLeft = dfs(grid, i+(m-i)/2+1, j, m, j+(n-j)/2);
            node.bottomRight = dfs(grid, i+(m-i)/2+1, j+(n-j)/2+1, m, n);
        }
        return node;
    }
}