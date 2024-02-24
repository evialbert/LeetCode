class Solution {
public:
    bool isSandP(string str1 , string str2){
         int n  = str1.size();
        int m = str2.size();
        if(m < n){
            return false;
        }
       if(str2.substr(0,n) == str1 && str2.substr(m-n,n) == str1){
           return true;
       }
        return false;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long cnt = 0 ;
        int n = words.size();
        map<string,int>m;
        m[words[n-1]]=true;
        for(int i =n-2  ; i >= 0 ; i--){
            string str1  = words[i];
         auto it = m.lower_bound(str1);
            while(it != m.end() && (str1 <= it->first)){
                if(isSandP(str1,it->first)) {
                cnt+= it->second;
                
                }
             it++;
            }
            m[str1]++;
        }
        return cnt;
    }
};