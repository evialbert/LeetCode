class Solution {
public:
    vector<int> prefixString(string s){
        int start=0, end=1;
        vector<int>pi(s.size());
        pi[0]=0;
        while(end<s.size()){
            if(s[start]==s[end]){
                pi[end]=start+1;
                start++;
                end++;
                
            }
            else{
                if(start!=0){
                    start=pi[start-1];
                }
                else{
                    pi[end]=0;
                    end++;
                }
            }
            
            
        }

        return pi;
    }

    vector<int> matchingIndex(string test, string pat){
        vector<int> pi=prefixString(pat);
        //for(auto x: pi)
            //cout<<x<<endl;
            vector<int> res;
            int i=0,j=0;
            while(i<test.size()){
                if(test[i]==pat[j]){
                    i++;
                    j++;
                }
                else{
                    if(j!=0)
                        j=pi[j-1];
                    else
                        i++;
                }

                if(j==pat.size()){
                    res.push_back(i-pat.size());
                    j=pi[j-1];
                }

            }
            return res;

    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int> v1=matchingIndex(s,a);
        vector<int> v2=matchingIndex(s,b);
        
        cout<<v1.size()<<v2.size();

        vector<int> res;

        for(int i=0,j=0;i<v1.size();i++){
            while(j<v2.size() && v1[i]>v2[j] && abs(v1[i]-v2[j])>k)
                j++;
            if(j<v2.size() && abs(v1[i]-v2[j])<=k)
                res.push_back(v1[i]);
        }

        return res;

    }
};