class Solution {
public:
    int distribute(vector<int>& cookies, int ind, vector<int>& bags){
        if(ind == cookies.size()){
            return *max_element(bags.begin(), bags.end());
        }
        int ans = INT_MAX;
        for(int i=0;i<bags.size();i++){
            bags[i] += cookies[ind];
            ans = min(ans, distribute(cookies, ind+1, bags));
            bags[i] -= cookies[ind];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>bags(k,0);
        return distribute(cookies, 0, bags);
    }
};