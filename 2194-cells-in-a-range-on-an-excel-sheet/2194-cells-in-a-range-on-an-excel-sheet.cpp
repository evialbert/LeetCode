class Solution {
public:
    vector<string> cellsInRange(string s) {
    char c1 = s[0] , c2 = s[3] , r1 = s[1] , r2 = s[4];
    vector<string>res;
    for(char c = c1; c <= c2; c++){
        for(char r = r1; r <= r2; r++){
            string str;
            str = c;
            str += r;
            res.push_back(str);
        }
    }
    return res;
}
};