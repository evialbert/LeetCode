class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0) return 0;
        stack<char> v;
        for(auto& itr : s){
            if(v.size()>0 && itr == v.top()) v.pop();
            else{
                if(itr == '(') v.push(')');
                else if(itr == '[') v.push(']');
                else if(itr == '{') v.push('}');
                else if(itr == ')') return 0;
                else if(itr == '}') return 0;
                else if(itr == ']') return 0;
            }
        }
        return v.empty();
    }
};