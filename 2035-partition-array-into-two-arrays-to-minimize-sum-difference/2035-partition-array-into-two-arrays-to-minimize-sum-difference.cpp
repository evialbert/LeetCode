class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        const int n = nums.size()/2;
        auto vv1 = init(vector(nums.begin(), nums.begin()+n));
        auto vv2 = init(vector(nums.begin()+n, nums.end()));
        const int sum = accumulate(nums.begin(), nums.end(), 0), target = sum/2;
        int res = 1e9;
        for(int k=0;k<=n;k++){
            auto &v1 = vv1[k], &v2 = vv2[n-k];
            for(int i=0, j=v2.size()-1; i<v1.size() && j>=0; i++){
                while(j >= 0 && v1[i] +v2[j] > target) j--;
                if(j+1<v2.size()) res = min(res, abs((v1[i]+v2[j+1])*2-sum));
                if(j>=0) res = min(res, abs((v1[i]+v2[j])*2-sum));
            }
        }
        return res;
    }

    vector<vector<int>> init(vector<int> v){
        int n = v.size();
        auto res = vector(n+1, vector<int>());
        res[0].push_back(0);
        for(auto& v:res) v.reserve(1<<n);
        dfs(v, 0, 0, 0, res);
        for(auto& v:res) sort(begin(v), end(v));
        return res;
    }

    void dfs(const vector<int>& v, int i, int len, int sum, vector<vector<int>>& res){
        if(i == v.size()) return;
        for(int j=i;j<v.size();j++){
            res[len+1].push_back(sum+v[j]);
            dfs(v, j+1, len+1, sum+v[j], res);
        }
    }
};