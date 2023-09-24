class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string res="";
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                swap(s[i],s[j]);
                j++;
            }
        }
        swap(s[j-1],s[s.size()-1]);
        return s;
    }
};