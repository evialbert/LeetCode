class Solution {
    
public:
    
    string removeStars(string s) {
        
        string ans = "" ;

        for(auto&k:s)
        {
            if( k == '*' )
                ans.pop_back() ;
            else
                ans.push_back(k) ;

        }

        return ans ;
        
    }
    
};
