class Solution {
    public boolean validTicTacToe(String[] board) {
        int[] counts = getCounts(board);
        
        int xCount = counts[0];
        int oCount = counts[1];
        
        //X count must be equal to O count/ O count + 1
        if(!(xCount == oCount || xCount == oCount + 1)) return false;
        
        //when X is winner, then X count must equal to O count + 1
        //if not retunr false
        if(isWinner(board, 'X') && xCount != oCount + 1) return false;
        
        //when O is winner, then X count must equal to O count
        if(isWinner(board, 'O') && xCount != oCount) return false;
        
        return true;
    }
    
    private boolean isWinner(String[] board, char c){
        
        //horizonal
        for(int i = 0; i < 3; i++){
            if(board[i].charAt(0) == c && board[i].charAt(1) == c  && board[i].charAt(2) == c) 
                return true;
        }
        
        //Vertical
        for(int i = 0; i < 3; i++){
            if(board[0].charAt(i) == c && board[1].charAt(i) == c  && board[2].charAt(i) == c) 
                return true;
        }
        
        //doagonal
        if(board[0].charAt(0) == c && board[1].charAt(1) == c  && board[2].charAt(2) == c) 
                return true;
         
        //anti diagonal
        if(board[0].charAt(2) == c && board[1].charAt(1) == c  && board[2].charAt(0) == c) 
                return true;
        
        return false;
        
    }
    
    private int[] getCounts(String[] board){
        int x = 0; // X count
        int o = 0; // Y Count 
        
        for(int i = 0; i < 3; i++){
            
            for(int j = 0; j < 3; j++){
                char c = board[i].charAt(j);
                if(c == 'X'){
                    x++;
                }else if(c == 'O'){
                    o++;
                }
            }
        }
        
        return new int[]{x, o};
    } 
}