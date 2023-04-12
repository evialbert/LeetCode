class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>ans;
        long long int sum=0;
        for(int i=0;i<word.size();i++)
        {
            int n=word[i]-'0';
            sum=sum*10+n;
            if(sum%m==0)
                ans.emplace_back(1);
            else
                ans.emplace_back(0);
            sum=sum%m;
        }
        return ans;
    }
};