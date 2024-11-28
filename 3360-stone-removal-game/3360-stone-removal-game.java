class Solution {
    public boolean canAliceWin(int n) {
        int stones = 10;
        if(n<10) return false;
        while(n>=stones){
            n= n-stones;
            stones--;
        }
        if(stones%2 == 0 ) return false;
        return true;
    }
}