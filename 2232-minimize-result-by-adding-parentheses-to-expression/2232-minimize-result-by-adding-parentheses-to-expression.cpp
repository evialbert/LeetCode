class Solution {
public:
    int addition(string s){
        int leftpart=0,rightpart=0;
        int i=0;
        while(s[i]!='('){
            i++;
        }
        i++;
        while(s[i]!='+'){
            leftpart=leftpart*10+(s[i]-'0');
            i++;
        }
        i++;
        while(s[i]!=')'){
            rightpart=rightpart*10+(s[i]-'0');
            i++;
        }
        
        return leftpart+rightpart;
    }
    int evaluate(string s){
        int before=0,after=0;
        int i=0;
        while(s[i]!='('){
            before=before*10+(s[i]-'0');
            i++;
        }
        i++;
        while(s[i]!=')'){
            i++;
        }
        i++;
        while(i!=s.length()){
            after=after*10+(s[i]-'0');
            i++;
        }
        if(before==0) before=1;
        if(after==0) after=1;
        // cout << addition(s);
        return before*(addition(s))*after;
        
    }
    
    string minimizeResult(string expression) {
        string ans,s,str,temp;
        int minimum=INT_MAX;
        int n=expression.find('+');
        
        for(int i=0;i<n;i++){
            s=expression;
            s.insert(i,"(");
            for(int j=s.length();j>n+2;j--){  
                temp = s;
                str = temp;
                str=temp.insert(j,")");
                int k = evaluate(str);
                // cout << str << " -> " << k << endl;
                if(k<minimum){
                    ans=str;
                    minimum=k;
                }
            }
        }
        return ans;
    }
};