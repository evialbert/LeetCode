class Solution {
    public boolean exist(char[][] board, String word) {
        int n=board.length;
        int m= board[0].length;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word.charAt(0)){
                    if(search(i,j,n,m,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    boolean search(int i,int j,int n,int m,char[][] board,String word,int k){

        // base case when word is full covered 
        if(k==word.length()){
            return true;
        }


        // extreme case which is not possible 
        if(i<0|| j<0 || i==n || j==m|| board[i][j]!=word.charAt(k)){
            return false;
        }

        char ch=board[i][j];
        board[i][j]='#'; //because backward na search kare isliye jo jo just piche hai ussko # kiya 

        boolean op1=search(i+1,j,n,m,board,word,k+1); //down
        boolean op2=search(i,j+1,n,m,board,word,k+1); //right
        boolean op3=search(i-1,j,n,m,board,word,k+1); //up
        boolean op4=search(i,j-1,n,m,board,word,k+1); //left

        board[i][j]=ch;
        return op1||op2||op3||op4;


    }
}