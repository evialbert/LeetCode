class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        string str = "";
        for(auto c: s){
            if(c!='(' && c!=')'){
                str += c;
                continue;
            }
            else if(c=='('){
                open++;
                str += c;
            }
            else{
                if(open>0){
                    open--;
                    str += c;
                }
            }
        }
        cout<<str;
        string ans = "";
        if(open){
            for(int i=str.size()-1;i>=0;i--){
                if(open && str[i]=='('){
                    open--;
                    continue;
                }
                else{
                    ans += str[i];
                }
            }
            reverse(ans.begin(),ans.end());
        }
        else{
            ans = str;
        }
        return ans;
    }
};