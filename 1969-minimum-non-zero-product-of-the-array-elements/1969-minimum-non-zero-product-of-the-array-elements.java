class Solution {
    static long mod = 1000000007L ;
    public int minNonZeroProduct(int p) {
        // m = 2^p -1
        long m = (long) Math.pow( 2, p ) -1L ;
        // System.out.println( "m: " + m ) ;
        long lhs = pow( m -1, m /2 ) ;
        
        return (int) ( ( (m %mod) * (lhs %mod) ) %mod) ;
    }
    
    public long pow( long x, long n ){
        if( n == 0 ){
            return 1 ;
        }
        
        long ans = pow( x, n /2 ) ;
        // System.out.println( x + "^" + n/2 + " = " + ans ) ;
        ans = (ans * ans) %mod ;
        
        if( n %2 != 0 ){
            
            ans = ( ans * (x %mod) ) %mod ;
        }
        return ans %mod ;
    }
}