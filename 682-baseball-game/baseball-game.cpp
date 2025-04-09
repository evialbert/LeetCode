class Solution {
public:
    int calPoints(vector<string>& v) {
        stack<int> st;
        int n = v.size();
        for(int i=0;i<n;i++){
            if(v[i]=="C") st.pop();
            else if(v[i]=="D"){
                int temp = st.top();
                st.push(temp*2);
            }
            else if(v[i]=="+"){
                int top = st.top();
                st.pop();
                int newTop = st.top();
                int sum = top + newTop;
                st.push(top);    // Push the first top element back
                st.push(sum);
            }
            else{
                int t = std::stoi(v[i]);
                st.push(t);
            }
        }
        int sum = 0;
        while(st.size()>0){
            sum += st.top();
            st.pop();
        }
        return sum;
        
    }
};