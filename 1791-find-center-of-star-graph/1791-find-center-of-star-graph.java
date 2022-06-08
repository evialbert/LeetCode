class Solution {
    public int findCenter(int[][] edges) {
    
  int c1 = edges[0][0];
  int c2 = edges[0][1];


    if(edges[1][0] == c1 || edges[1][1] == c1)
        return c1;
    else
        return c2;
    
    
}
}