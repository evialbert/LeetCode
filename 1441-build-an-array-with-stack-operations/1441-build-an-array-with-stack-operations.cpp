class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int j=0;
        for(int i=1;i<=n;i++)
        {
            res.push_back("Push");
            if(target[j]==i)
                j++;
            else
               res.push_back("Pop"); 
            if(j==target.size())
                break;
        }
        return res;
    }
};