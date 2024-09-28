class Solution 
{
public:
    long long validSubstringCount(string word1, string word2) 
    {
        map<char,long long> m1, m2;
        for(auto ch: word2) m2[ch]++;
        long long cnt=0, target=m2.size();
        long long start=0, ans=0, end=0;
        while(end<word1.size())
        {
            m1[word1[end]]++;
            if(m1[word1[end]]==m2[word1[end]]) cnt++;
            while(cnt==target)
            {
                ans+=(word1.size()-end);
                m1[word1[start]]--;
                if(m1[word1[start]]<m2[word1[start]]) cnt--;
                start++;
            }
            end++;
        }
        return ans;
    }
};