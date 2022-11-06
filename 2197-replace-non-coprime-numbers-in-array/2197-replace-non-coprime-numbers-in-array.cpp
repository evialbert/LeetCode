class Solution {
public:
    #define ll long long  
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<ll> st ;
        for(int i = 0 ; i < nums.size() ;++i ){
            st.push(nums[i]) ;
            while(st.size() >= 2){
                ll a = st.top() ; st.pop() ;
                ll b = st.top() ; st.pop() ;
                if(__gcd(a,b) > 1) st.push((a*b) / __gcd(a,b)) ;
                else{
                    st.push(b) ; 
                    st.push(a) ;
                    break ;
                }
            }
        }
        vector<int> ans ;
        while(!st.empty()){
            ans.push_back(st.top()) ;
            st.pop() ;
        }
        reverse(begin(ans),end(ans)) ;
        return ans ;
    }
};