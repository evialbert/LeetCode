class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto x:words){
            if(x.size()==1) return x;
            int i=0,j=x.size()-1;
            bool flag=false;
            while(i<j){
                if(x[i++]!=x[j--]){
                    flag=false;
                    break;
                }
                else
                    flag=true;
            }
            if(flag)
                return x;
        }
        return "";
    }
};