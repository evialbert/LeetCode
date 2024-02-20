class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        map < int , int > mp ;
        for ( int i = 0 ; i < nums.size() ; i++ )
            mp [ nums[i] ]++ ;
        for( int i = 0 ; i <= nums.size() ; i++ )
            if ( mp [i] == 0 )
                return i;
        return -1 ;
    }
};