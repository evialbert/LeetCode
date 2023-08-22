class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber){
            columnNumber--;
            int r=columnNumber%26;
            char c='A'+r;
            ans=c+ans;
            columnNumber/=26;
        }
        return ans;
    }
};