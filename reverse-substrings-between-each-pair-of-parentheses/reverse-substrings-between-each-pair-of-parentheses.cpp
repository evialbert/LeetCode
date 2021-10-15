class Solution {
public:
   string reverseParentheses(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++){
    if (s[i] == '(') {
	   st.push(i);
	 }
    else if (s[i] == ')'){
        int beg = st.top();
        int end = i;
        reverse(s.begin() + beg, s.begin() + end);
        st.pop();
    }
}
		
string ans; 
for (int i = 0; i < s.size(); i++){ 
    if (s[i] == '(' || s[i] == ')'){
	    continue;
	}
    else ans.push_back(s[i]);
    }
return ans;
}
};