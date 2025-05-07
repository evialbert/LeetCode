class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = (int)skill.size();
        int m = (int)mana.size();
        vector<vector<long long>> table(m, vector<long long>(n, 0));
        vector<long long> pref(n, 0);
        for(int i=0;i<n;++i){
            pref[i] = (i > 0 ? pref[i-1] : 0) + skill[i];
        }
        for(int i=0;i<n;++i){
            table[0][i] = pref[i] * mana[0];
        }
        for(int i=1;i<m;++i){
            long long ctime = table[i-1][0];
            for(int j=0;j<n-1;++j){
                ctime = max(ctime, table[i-1][j+1] - 1LL * pref[j] * mana[i]);
            }
            for(int j=0;j<n;++j){
                table[i][j] = ctime + 1LL * pref[j] * mana[i];
            }
        }
        // for(int i=0;i<m;++i){
        //     for(int j=0;j<n;++j){
        //         cout << table[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return table[m-1][n-1];
        
    }
};

