class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        string temp=word;
        int j,n=word.size(),ans=0;
        for(int i=0;i<n;i+=k){
            j=i;
            while(j<k+i){
                temp[j]='*';
                j++;
                if(j==n)
                return ans+1;
            }
            ans++;
            cout<<word.substr(j,n-j)<<" - "<<word.substr(0,n-j)<<endl;
            if(word.substr(j,n-j)==word.substr(0,n-j))
            return ans;
            

        }
        return ans;
    }
};