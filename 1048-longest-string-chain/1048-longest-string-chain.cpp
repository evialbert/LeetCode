class Solution {

bool check(string s1, string s2){
    if(s1.size() != s2.size()+1) return false;

    int ptr1 = 0;
    int ptr2 = 0;
    while(ptr1 < s1.size()){
        if(s1[ptr1] == s2[ptr2]){
            ptr1++;
            ptr2++;
        }
        else{
            ptr1++;
        }
    }

    if(ptr1 == s1.size() && ptr2 == s2.size()){
        return true;
    }
    return false;
}
 static bool compare(string& s1, string& s2) {
    return s1.size() < s2.size(); 
}
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 1;
        vector<int> dp(n,1);

        sort(words.begin(), words.end(), compare);
        
          for(int i=1; i<n; i++){
            for(int j =0; j<i; j++){
               
               if(check(words[i],words[j]) &&  1+dp[j] > dp[i]){
                 dp[i] = dp[j] + 1;
               }
              
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
          }
          return maxi;
    }
};