class Solution {
public:
    int minimumPushes(string s) {
        int n =(int)s.size() ; 
        vector <int> v(26,0) ;  
        for(int i = 0 ; i < n ; i++){
             v[s[i] - 'a']++ ; 
        }
        sort(v.begin() , v.end()) ;
        reverse(v.begin() , v.end()) ; 
        int ans = 0 ; 
        for(int i = 0 ; i < (int)v.size() ;i++){
            if(i < 8){
                ans += v[i]*1 ; 
            }
            else if(i >= 8 && i < 16){
                ans += v[i]*2 ; 
            }
            else if(i >= 16 && i < 24){
                ans += v[i]*3 ; 
            }
            else{
                ans += v[i]*4 ; 
            }
        }
        return ans ; 
    }
};