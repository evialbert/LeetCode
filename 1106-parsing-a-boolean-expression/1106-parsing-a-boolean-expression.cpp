class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> s;
        for(auto x:e){
            if(x=='(' || x==',') continue;
            if(x==')'){
                bool t = false;
                bool f = false;
                while(s.top() == 't' || s.top() == 'f'){
                    if(s.top() == 't') t = true;
                    if(s.top() == 'f') f = true;
                    s.pop();
                }
                
                char ex = s.top();
                s.pop();
                char p;
                if(ex=='&'){
                    p=f?'f':'t';
                }
                else if(ex=='|'){
                    p=t?'t':'f';
                }
                else{
                    p=t?'f':'t';
                }
                s.push(p);
                continue;
            }
            s.push(x);
        }
        return s.top()=='t'? true:false;
    }
};