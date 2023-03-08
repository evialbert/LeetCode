class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&k](auto& l, auto& r)->bool{
            return l[k] > r[k];
        });
        return score;
    }
};