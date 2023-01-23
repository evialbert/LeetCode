class Solution {
public:
bool check(string s){
    string p=s;
    reverse(p.begin(),p.end());
    if(s==p){
        return true;
    }
    return false;
}
    bool isStrictlyPalindromic(int n) {
         for(int i=2;i<n-1;i++){
             string s="";
             int x=n;
             while(x>0){
                 string t=to_string(x%i);
                 s+=t;
                 x/=i;
             }
             if(check(s)==false){
                 return false;
             }
         }
         return true;
    }
};