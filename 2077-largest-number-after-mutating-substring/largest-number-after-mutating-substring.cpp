class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int i=0;
        while (i<num.length() && (num[i]-'0') >= change[num[i]-'0']) {
            i++;
        }
        while (i<num.length() && (num[i]-'0') <= change[num[i]-'0']) {
            num[i] = char('0'+change[num[i]-'0']);
            i++;
        }
        return num;
    }
};