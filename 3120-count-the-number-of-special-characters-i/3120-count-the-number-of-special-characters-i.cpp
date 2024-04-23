class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        unordered_map<char, int>mp1, mp2;
        // vector<char>v1,v2;
        for(int i=0; i<word.size(); i++){
            if(word[i] >= 'a' && word[i] <= 'z')mp1[word[i]]++;
            if(word[i] >= 'A' && word[i] <= 'Z')mp2[word[i]]++;
        }
        for(auto it:mp1){
            for(auto its:mp2){
                if(it.first == tolower(its.first))cnt++;
            }
        }
        return cnt;
    }
};