class Solution {
public:
    string lexSmallest(string s) {
        string ans=s;
        int n=s.size();
        for(int i=1;i<=n;i++){
            string temp=s;
            reverse(temp.begin(),temp.begin()+i);
            ans=min(ans,temp);
        }
        for(int i=0;i<=n;i++){
            string temp=s;
            reverse(temp.end()-i,temp.end());
            ans=min(ans,temp);
        }
        return ans;
    }
};