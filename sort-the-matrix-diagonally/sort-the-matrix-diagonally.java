class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        for(int i=0;i<n;i++){
            int x=i,y=0,index=0;
            ArrayList<Integer> list = new ArrayList();
            while(x<n && y<m){
                list.add(mat[x][y]);
                x++;y++;
            }
            Collections.sort(list);
            x=i;y=0;
            while(x<n && y<m){
                mat[x][y]=list.get(index++);
                x++;y++;
            }  
        }
        for(int i=1;i<m;i++){
            int x=0,y=i,index=0;
            ArrayList<Integer> list = new ArrayList();
            while(x<n && y<m){
                list.add(mat[x][y]);
                x++;y++;
            }
            Collections.sort(list);
            x=0;y=i;
            while(x<n && y<m){
                mat[x][y]=list.get(index++);
                x++;y++;
            }  
        }
        return mat;
    }
}