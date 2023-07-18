class Solution {
public:
    int minOperationsToFlip(string s) {
        
       stack<pair<char,int>>st;
       int i=0;
       int n=s.length();
       pair<char,int>p;
        while(i<n){
            if(s[i]=='&'|| s[i]=='|' || s[i]=='('){
                p={s[i],0};
            }else{
                if(s[i]==')'){
                    p=st.top();
                    st.pop();
                    st.pop();
                }else{
                    p={s[i],1};
                }
               
                if(!st.empty() && (st.top().first=='|' || st.top().first=='&')){
                    
                    char curr =st.top().first;
                    st.pop();
                    char left=st.top().first;
                    char leftc=st.top().second;
                    st.pop();
                    char right=p.first;
                    char rightc=p.second;
                    
                     if(curr=='&' && left=='1' && right=='1') p={'1',min(leftc,rightc)};
                     if(curr=='&' && left=='1' && right=='0') p={'0',1};
                     if(curr=='&' && left=='0' && right=='1') p={'0',1};
                     if(curr=='&' && left=='0' && right=='0') p={'0',min(leftc,rightc)+1};
                    
                     if(curr=='|' && left=='1' && right=='1') p={'1',min(leftc,rightc)+1};
                     if(curr=='|' && left=='0' && right=='1') p={'1',1};
                     if(curr=='|' && left=='1' && right=='0') p={'1',1};
                     if(curr=='|' && left=='0' && right=='0') p={'0',min(leftc,rightc)};
                    
                }
                 
            }
            
            st.push(p);
            i++;
        }
        return st.top().second;
      
        
    }
};
