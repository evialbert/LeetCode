class Solution {
public:
    string reverseWords(string s) {
     
        int i = 0 ;
        
        while(i<s.length())
        {
            int j = i;
            
            // Traverse forward till you find a space or you reach to end
            while(j<s.length() && s[j] != ' ')
                j++;
            
            // previous position from j will be of last character of a word
            int k = j-1;
            
            // Reversing That Word
            while(i<k)
                swap(s[i++], s[k--]);
            
            // now next word will start from next position of j
            i = j+1;
        }
        
        return s;
    }
};