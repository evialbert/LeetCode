class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n=arr.size();
        int kth=INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<kth)return true;
            else {
                while(!st.empty() and arr[i]>st.top()){
                    kth=st.top();
                    st.pop();
                }
            }
            st.push(arr[i]);
        }
        return false;
    }
};