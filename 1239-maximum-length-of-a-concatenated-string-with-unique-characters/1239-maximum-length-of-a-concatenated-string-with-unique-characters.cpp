class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<pair<int, int>> sig;
        for(int i = 0; i < arr.size(); i++){
            int signature = 0;
            bool good = true;
            for(auto& c : arr[i]) {
                int cIdx = (1 << (c - 'a'));
                if(signature & cIdx){ good = false; break; } // Prevent dups in same string
                signature |= cIdx;
            }
            if(good) sig.push_back({ arr[i].size(), signature });
        }
        return dfs(0, 0, sig);
    }

    int dfs(int index, int cum, vector<pair<int, int>>& arr){
        if(index == arr.size()) return 0;

        auto&[size, sig] = arr[index];
        int choose = INT_MIN; int nochoose = INT_MIN;
        
        if(!(sig & cum)){
            choose = size + dfs(index + 1, cum | sig, arr);
        }

        nochoose = dfs(index + 1, cum, arr);
        return max(choose, nochoose);
    }
};