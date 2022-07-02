class Solution {
public:
    bool sumGame(string num) {
    int bal = 0, balq = 0;
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] == '?')
            balq += (i < num.size() / 2 ? 1 : -1);
        else
            bal +=  (i < num.size() / 2 ? 1 : -1) * (num[i] - '0');
    }
    return balq & 1 || bal + balq * 9 / 2 != 0;
}
};