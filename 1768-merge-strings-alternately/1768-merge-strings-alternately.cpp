class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,m=word1.size(),n=word2.size(),cnt=0;
        string ans;
        while(i<m && j<n){
            if(cnt%2){
                ans += word2[j];
                j++;
            }
            else{
                ans += word1[i];
                i++;
            }
            cnt++;
        }
        while(i<m){
            ans += word1[i];
            i++;
        }
        while(j<n){
            ans += word2[j];
            j++;
        }
        return ans;
    }
};