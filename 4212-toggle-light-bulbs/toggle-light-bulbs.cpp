class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> v(101,false);
        for(int bulb:bulbs){
            v[bulb]=!v[bulb];
        }
        vector<int> ans;
        for(int i=0;i<101;i++){
            if(v[i]) ans.push_back(i);
        }
        return ans;
    }
};