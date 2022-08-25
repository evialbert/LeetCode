class Solution {
    public int minimumMoves(String s) {
        int res=0; int i=0;
        while(i<s.length()){
            char ch= s.charAt(i);
            if(ch == 'X'){
                res++;
                i+=3;
            } else{
                i++;
            }
        }
        
        return res;
        
    }
}