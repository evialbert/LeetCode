class Solution {
    public int maxDifference(String s) {
        int[] f = new int[26] ; 
        int odd_max = 1 ; 
        int odd_min = Integer.MAX_VALUE  ;
        int even_max = 1 ;
        int even_min = Integer.MAX_VALUE ; 
        for( char c : s.toCharArray() ){
            f[ c - 'a' ]++ ; 
        }
        for( int i=0 ; i<26 ; ++i ){
            if( f[i] % 2 == 1 ){
                odd_max = Math.max( odd_max , f[i] ) ; 
                odd_min = Math.min( odd_min , f[i] ) ; 

            }else if( f[i] > 0 ){
                even_max = Math.max( even_max , f[i] ) ; 
                even_min = Math.min( even_min , f[i] ) ; 
            }
        }
        int rs =  odd_max - even_min ; 
        return rs ; 
    }
}