class Solution {
    public List<Integer> zigzagTraversal(int[][] grid) {
        List<Integer> ans=new ArrayList<>();
        int r=grid.length, c=grid[0].length;
        int curr=0;
        int i=0,j=-1;
        while(i<r){
            if(j<0){
                for(j=0;j<c;j++){
                    if(curr%2==0){
                        ans.add(grid[i][j]);
                    }
                    curr++;
                }
            }
            else{
                for(j=c-1;j>=0;j--){
                    if(curr%2==0){
                        ans.add(grid[i][j]);
                        
                    }
                    curr++;
                }
            }
            i++;
        }
        return ans;
    }
}