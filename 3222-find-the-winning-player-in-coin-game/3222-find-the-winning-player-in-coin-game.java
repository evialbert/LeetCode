class Solution {
    public String losingPlayer(int x, int y) {
		//Create an array of players
        String[] arr = {"Bob", "Alice"};
        int flag =0;
		//if there are enough coins to win
        while(x>=1 && y>=4){
            x-=1;
            y-=4;
			//Change player turn
            flag = (flag == 0) ? 1 : 0;
        }
        return arr[flag];        
    }
}