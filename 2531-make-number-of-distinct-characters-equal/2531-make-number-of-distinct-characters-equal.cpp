class Solution {
public:
    bool isItPossible(string word1, string word2) {
         vector<int> left(26,0),right(26,0);
        for(int i=0;i<word1.size();i++){
            left[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++){
            right[word2[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(left[i]>0 && right[j]>0){
                    left[i]--;right[j]--;
                    right[i]++;left[j]++;
                int cnt1=0,cnt2=0;
                for(int k=0;k<26;k++){
                    if(left[k]>0)cnt1++;
                    if(right[k]>0)cnt2++;
                }
                if(cnt1==cnt2)return true;
                    left[i]++;right[j]++;
                    right[i]--;left[j]--;
                }
            }
        }
        return false;
    }
};