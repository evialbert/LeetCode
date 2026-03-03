class Solution {
public:
    string reversePrefix(string s, int k) {
        int left = 0 , right = k-1;
        while(left<right){
            swap(s[left++],s[right--]);
        }
        return s;
    }
};