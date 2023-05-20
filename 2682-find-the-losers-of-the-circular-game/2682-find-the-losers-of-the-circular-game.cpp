class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int>ans(n,1);
        vector<int>ans2;
        int i=2;
        ans[0]=0;
        int first=0,temp=k;
       
        while(true)
        {
            
            first=(first+temp)%n;
            if(ans[first]==0) break;
            else
            {

            ans[first]=0;
            temp=k*i;
            i++;
            }
        }
        for(int j=0;j<ans.size();j++)
        {
            if(ans[j]==1) {ans2.push_back(j+1);}
        }
        return ans2;
        
    }
};
