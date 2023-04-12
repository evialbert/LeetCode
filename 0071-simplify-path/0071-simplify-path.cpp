class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string ans, temp;
        int n = path.size();
        stringstream X(path);
        
        while(getline(X, temp, '/')){
            if(temp == "" || temp == ".") continue;
            if(temp != ".." ) s.push(temp);
            else if(!s.empty()) s.pop();
        }
        if(s.empty()) return "/";
        
        while(!s.empty()){
            ans = '/' + s.top() + ans;
            s.pop();
        }
        return ans;
    }
};