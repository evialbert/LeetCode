class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        int n=s.length();
        int ans=0;
        
        for(int i=0;i<n;i++){
            vector<int>v(26,0);

            for(int j=i;j<n;j++){
                char ch=s[j];
                v[ch-'a']++;
                bool flag=false;

                for(int l=0;l<26;l++){
                    if(v[l]>=k)flag=true;
                }

                if(flag==true)ans++;
            }
        }

        return ans;
    }
};