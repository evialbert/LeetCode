class Solution {
public:
    vector<string> res;
    vector<string> getNums(string s){
        vector<string> result;
        int n=s.size();
        if(n==1)
        return {s};

        if(s[0]!='0')
        result.push_back(s);

        if(s[0]=='0'){
            if(s[n-1]!='0')
            return {"0."+s.substr(1)};
            else
            return {};
        }

        for(int i=1;i<n;i++){
            if(s.substr(i).back()=='0')
            continue;

            auto str=s.substr(0, i)+"."+s.substr(i);
            result.push_back(str);
        }

        return result;


    }
    void helper(string& s){

        for(int i=1;i<s.size();i++){
            auto left=getNums(s.substr(0, i));
            auto right=getNums(s.substr(i));

            for(auto l:left){
                for(auto r:right){
                    res.push_back("("+l+", "+r+")");
                }
            }
        }

        

    }

    vector<string> ambiguousCoordinates(string s) {

        s=s.substr(1, s.size()-2);
        helper(s);
        return res;
    }
};