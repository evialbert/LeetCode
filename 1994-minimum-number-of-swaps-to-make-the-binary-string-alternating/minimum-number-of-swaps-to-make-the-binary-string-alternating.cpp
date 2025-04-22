class Solution {
public:
    int minSwaps(string s) {
        int n = s.size(), cnt_one = 0, cnt_zero = 0, start = -1;
        for(auto x : s)
            if( x == '0' )
                cnt_zero++;
            else
                cnt_one++;
        if( n% 2 == 0 && cnt_one != cnt_zero )
            return -1;
        if( n% 2 != 0 && abs( cnt_one - cnt_zero ) != 1 )
            return -1;  

        if ( cnt_zero > cnt_one )
            start = 0;
        if ( cnt_zero < cnt_one )
            start = 1;
        
        cnt_one = 0, cnt_zero = 0;
        for( int i = 0; i < n; i+=2 )
            if( s[i] == '0' )
                cnt_zero++;
            else
                cnt_one++;
        
        return ( start == -1 ) ? min(cnt_zero, cnt_one) : ( start == 0 ) ? cnt_one : cnt_zero;
    }
};