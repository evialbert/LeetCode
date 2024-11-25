class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string,int> m;
        int  n= s.size();

        int len = n/k;
        
        for(int i=0;i<n-len+1;i+=len){
            m[s.substr(i,len)]++;
        }   
      
        for(int i=0;i<n-len+1;i+=len){
            if(m[t.substr(i,len)]){
                m[t.substr(i,len)]--;
            }else{
                return false;
            }
        }
        return true;
    }
};