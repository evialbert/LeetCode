class Solution {
    public int maximumGood(int[][] statements) {
        int n = statements.length;
        int res = 0;
        
        for(int i = 0; i < (1 << n); i++) {
            if(isValidGuess(statements, i)) {
                res = Math.max(res, countActiveBits(i));
            }
        }
        
        return res;
    }
    
    private boolean isValidGuess(int[][] statements, int guess) {
        int n = statements.length;
        
        for(int i = 0; i < n; i++) {
            // if i-th person is a good person
            if(isGuessedAsGood(guess, i, n)) {
                // Since i is a good person, all the statements by i would be true
                // So check if the statements given by i for other people
                // and the guess made by us for those people are the same
                // if not then the guess that we have made is not valid and return false
                for(int j = 0; j < n; j++) {
                    if(statements[i][j] != 2 &&
                       statements[i][j] != (isGuessedAsGood(guess, j, n) ? 1 : 0)) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    private boolean isGuessedAsGood(int guess, int person, int total) {
        // a person is a good person if the (n - 1 - i)th bit is 1
        return (guess & (1 << (total - 1 - person))) > 0;
    }
    
    private int countActiveBits(int num) {
        int c = 0;
        
        while(num > 0) {
            if((num & 1) > 0)
                c++;
            
            num >>= 1;
        }
        
        return c;
    }
    
}