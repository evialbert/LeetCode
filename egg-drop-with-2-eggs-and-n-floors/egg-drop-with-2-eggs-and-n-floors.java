class Solution {
    public int twoEggDrop(int n) {
        int i = 1;
        
        while(n > 0){
            n -= i;
            i++;
        }
        
        return --i;
    }
}