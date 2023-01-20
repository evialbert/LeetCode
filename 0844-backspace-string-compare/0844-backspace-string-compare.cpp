class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string fir="";
        string sec ="";
        
        for(auto ch : s){
            if(ch=='#'){
                if(!fir.empty())
                    fir.pop_back();
            }
            else{
                fir.push_back(ch);
            }
        }
        
        for(auto ch : t){
            if(ch=='#'){
                if(!sec.empty())
                    sec.pop_back();
            }
            else{
                sec.push_back(ch);
            }
        }
        
        return sec==fir;
    }
};