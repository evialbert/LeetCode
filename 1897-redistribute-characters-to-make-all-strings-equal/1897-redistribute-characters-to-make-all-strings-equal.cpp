class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>m;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                m[words[i][j]]++;
            }
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(m[words[i][j]]%words.size()!=0){
                    return false;
                }
            }
        }
        return true;
    }
};