class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int count = 1;
        bool flag=false;
        if (k == word.size()) return 1;
        for (int i = k; i < word.size(); i += k) {
            int m=i,n=word.size()-1;
            int j=0,l=word.size()-i-1;
            while(m<=n)
            {
                if(word[m]==word[j]&&word[n]==word[l])
                {
                m++;
                n--;
                j++;
                l--;
                }
                else
                {
                    flag=true;
                    break;
                }
            }
            if(flag){
                count++;
                flag=false;
            }
            else break;
            
        }

        return count;
    }
};
