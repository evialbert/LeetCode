class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n,0);
        if(k==0)
            return ans;
        for(int i=0; i<n; i++)
        {
            int j=0, sum=0, count=k;
            if(k>0)
            {
                j=i+1;
                while(count--){
                    sum+=code[j%n];
                    j++;
                }
            }
            else
            {
                if(i==0)  j=n-1;
                else   j=i-1;
                while(count++){
                    sum+=code[j];
                    if(j==0)    j=n-1;
                    else     j--;
                }
            }
            ans[i]=sum;
        }
        return ans;
    }
};
