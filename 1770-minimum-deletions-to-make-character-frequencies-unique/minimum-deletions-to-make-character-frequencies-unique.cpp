class Solution {
public:
    int minDeletions(string s) {
        int freq[26]={0};
        
        int l=s.length();
        
        for(int i=0;i<l;i++)
            freq[s[i]-'a']++;
        
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]==0)
                continue;
            for(int j=0;j<26;j++)
            {
                if(i!=j && freq[i]==freq[j])
                {
                    freq[i]--,ans++,i--;
                    break;
                }
            }
        }
        return ans;
    }
};