class Solution {
public:
    string resultingString(string s) {
        int n= s.size();
        string ans;
        for(auto it:s){
            if(!ans.empty()){
                int d=abs(ans.back()-it);
                if(d==1|| d==25){
                    ans.pop_back();
                    continue;
                }
            }
            ans+=it;
        }
        return ans;
    }
};