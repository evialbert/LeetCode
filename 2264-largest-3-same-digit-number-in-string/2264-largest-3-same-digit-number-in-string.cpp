class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int n=num.size();
        char maxi='/';
     for(int i=1;i<n-1;i++)
    {
        if(num[i-1]==num[i] && num[i]==num[i+1])
        {
          maxi=max(num[i],maxi);
        }

    }
    for(int i=0;i<3;i++)
    {
       if(maxi!='/')
        ans+=maxi;
    }
   return ans;
    }
};