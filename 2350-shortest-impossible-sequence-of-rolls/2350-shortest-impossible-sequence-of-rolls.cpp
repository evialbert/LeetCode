class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n=rolls.size(),ans=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[rolls[i]]++;
            if(m.size()==k){
                ans++;
                m.clear();
            }
        }
        return ans+1;
    }
};