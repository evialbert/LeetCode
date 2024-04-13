class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int c = 0; // ans
        int op = 0; // Open Parantheses
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '('){
                op++;
            }
            else{
                if(i+1<n && s[i+1]==')'){
                    i++; // two times ')' present for one '(' move forward
                }
                else{
                    c++; // only one ')' , so insert one more ')'
                }
                if(op==0){
                    c++; // if no corresponding opening para then add one by insertion
                }
                else op--; // else '(' has corresponding two ')'
            }
        }
        if(op>0) c+= op*2; // for all '(' left insert corresponding '))'
        return c;
    }
};