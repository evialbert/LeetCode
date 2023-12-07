class Solution {
public:
    string largestOddNumber(string num) {
        int l=num.size()-1;
        while(!num.empty()&&num[l--]%2==0)
            num.pop_back();
        return num;
    }
};