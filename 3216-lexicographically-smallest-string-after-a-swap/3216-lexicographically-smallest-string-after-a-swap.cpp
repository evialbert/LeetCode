class Solution {
public:
    string getSmallestString(string s) {
        
        int n = s.length();
        
        for(int i=0; i<n-1; i++) {
            int t1 = s[i]-'0';
            int t2 = s[i+1]-'0';
            
            if(t1%2 == t2%2 && t2 < t1) {                
                s[i] = t2+'0';
                s[i+1] = t1+'0';
                break;
            }
        }
        
        return s;        
    }
};