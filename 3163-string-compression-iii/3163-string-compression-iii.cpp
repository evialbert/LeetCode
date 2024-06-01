class Solution {
public:
    string compressedString(string word) {
        string s="";
        int i=0;
        int j=0;
    
        while(i<word.length()){
            if(word[i]==word[i+1] && i-j+1<9){
                i++;
            }
            else{
                s+=to_string(i-j+1)+word[i];
                j=++i;
            }
        }
        return s;
        
    }
};