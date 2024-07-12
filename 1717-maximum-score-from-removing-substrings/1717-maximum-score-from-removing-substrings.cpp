class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
        vector<char>st,st1;int sum=0;
        if(x<y){
            
            for(auto i : s)
            {
                if(i!='a')st.push_back(i);
                else{
                    if (!st.empty() && st.back() == 'b'){
                        sum+=y;
                        
                        st.pop_back();
                    }
                    else{
                        st.push_back(i);
                    }
                }
            }
            for(auto i : st)
            {   
                if(i!='b')st1.push_back(i);
                else{
                    if(!st1.empty() && st1.back()=='a'){
                        sum+=x;
                        
                        st1.pop_back();
                    }
                    else{
                        st1.push_back(i);
                    }
                }
            }

        }
        else{
            
            for(auto i : s)
            {   
                if(i!='b')st.push_back(i);
                else{
                    if(!st.empty() && st.back()=='a'){
                        sum+=x;
                        
                        st.pop_back();
                    }
                    else{
                        st.push_back(i);
                    }
                }
            }
            for(auto i : st)
            {
                if(i!='a')st1.push_back(i);
                else{
                    if(!st1.empty() && st1.back()=='b'){
                        sum+=y;
                        
                        st1.pop_back();
                    }else{
                        st1.push_back(i);
                    }
                }
            }
        }
        return sum;
    }
};