/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        int high = n;
        int result = 1;
        while(low<= high){
            int middle = low+ (high-low)/2;
            if(guess(middle) == 0){
                return middle;
            }else if(guess(middle) == 1){
                low = middle+1;
            }else{
                high = middle-1;
            }
        }
        return result;
    }
}