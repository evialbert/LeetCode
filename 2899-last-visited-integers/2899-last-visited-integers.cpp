class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums;
        vector<int> ans;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]=="prev")
            {
                int cnt=1;
                int j=i;
                while(j-1>=0 && words[j]==words[j-1])
                {
                    cnt++;
                    j--;
                }
                vector<int> temp=nums;
                reverse(temp.begin(),temp.end());
                if(cnt-1>=temp.size()) ans.push_back(-1);
                else ans.push_back(temp[cnt-1]);
            }
            else nums.push_back(stoi(words[i]));
        }
        return ans;
    }
};