class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> vec;
        string temp="";
        for(auto ch:s1){
            if(ch==' '){
                vec.push_back(temp);
                temp="";
            }
            else{
                temp+=ch;
            }
        }
        vec.push_back(temp);
        temp="";
        for(auto ch:s2){
            if(ch==' '){
                vec.push_back(temp);
                temp="";
            }
            else{
                temp+=ch;
            }
        }
        vec.push_back(temp);
        unordered_map<string,int> unique;
        for(auto ele:vec){
                unique[ele]++;
        }
        vector<string> ans;
        for(auto ele:unique){
                if(ele.second == 1){
                    ans.push_back(ele.first);
                }
        }
        return ans;
    }
};