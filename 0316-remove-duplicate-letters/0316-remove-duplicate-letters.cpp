class Solution {
public:
   string removeDuplicateLetters(string s) {

     int n=s.size();
     string res="";
     unordered_map<char,int>m;
    
    for(char it:s)
        m[it]++;
    
    
    vector<int>v(26,-1);
    stack<char>st;
    
    for(char i:s){
        
        m[i]--;
        
        if(v[i-'a']!=-1) continue;
       
        while(!st.empty() && st.top()>i && m[st.top()]>0){
            v[st.top()-'a']=-1;
            st.pop();  
        }
        
        st.push(i);
        v[i-'a']=1;
        
    }
    

    
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    
    reverse(res.begin(),res.end());
    
    return res;
}
};