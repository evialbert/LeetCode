class Solution {
public:
    
    bool checkVowel(string s){
        string vowel = "aeiou";
        int n = s.length()-1;
        
        if(vowel.find(s[0])!=string::npos && vowel.find(s[n])!=string::npos){
            return true;
        }
        
        return false;
    }
    
    int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;
        for(int i=left; i<=right; i++){
            if(checkVowel(words[i])){
                res++;
            }
        }
        return res;
    }
};