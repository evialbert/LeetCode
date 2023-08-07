class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ans;
        for(auto i:words){
            string s="";
            for(char x : i){
                if(x!=separator){
                    s+=x;
                }else{
                    if(s != ""){
                        ans.push_back(s);
                        s="";
                    }
                }
            }
            if(s!= "") ans.push_back(s);
        }
        return ans;
    }
};