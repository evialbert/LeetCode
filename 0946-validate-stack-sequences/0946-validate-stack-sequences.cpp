class Solution {
public:
     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int idx=0;
        for(auto i:pushed){
            s.push(i);
            while(!s.empty() && s.top()==popped[idx]){
                s.pop();
                idx++;
            }
        }
        return s.empty();
    }
};