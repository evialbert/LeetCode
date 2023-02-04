class Solution {
public:
    string oddString(vector<string>& words) {
        for(int j=1;j<words[0].size();j++){
            unordered_map<int,int> m;
            for(int i=0;i<words.size();i++){
                m[words[i][j]-words[i][j-1]]+=i;
            }
            if(m.size()!=1){
                for(auto i=m.begin();i!=m.end();i++){
                    if(i->second<words.size()){
                        return words[i->second];
                    }
                }
            }
        }
        return "allAresame";
    }
};