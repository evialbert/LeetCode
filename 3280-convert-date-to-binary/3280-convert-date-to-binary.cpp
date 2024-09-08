class Solution {
public:
    string solve(string s) {
        string ans = "";
         int tmp = 0;

         for(int i=0; i<s.size(); i++) {
             tmp = tmp*10 + (s[i]-'0');
         } 

         while(tmp) {
            ans = ((tmp%2 == 0) ? "0" : "1") + ans;
            tmp /= 2;
         }

         return ans;
    }

    string convertDateToBinary(string s) {
         
         return solve(s.substr(0, 4)) + "-" + solve(s.substr(5, 2)) + "-" + solve(s.substr(8, 2));
    }
};