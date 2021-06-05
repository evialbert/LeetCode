class Solution {
    public int maxAreaOfIsland(int[][] grid) {
       
        int area=0; // max area
       
        for(int i=0;i<grid.length;i++){ // looping thorugh every element of grid
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j] ==1) // if a  land is found
                area=Math.max(area,rec(grid,i,j)); // get the maximum  area
            }
        }
        return area;
    }
    
    public int rec(int[][] grid,int i,int j){
        if(i<0 || i>=grid.length || j<0 || j>=grid[0].length || grid[i][j]!= 1) // boundary check 
		return 0;
        grid[i][j] = 0; //making cells 0 so as to know that it is visited
        return 1+ rec(grid,i-1,j)+rec(grid,i+1,j)+rec(grid,i,j-1)+rec(grid,i,j+1); // call to left,right,up and down
		// Initial 1 is for the 1st land encountered
        
    }
}