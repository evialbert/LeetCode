class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int ans = 1;
        unordered_map<int,int> m; // number - frequency
        unordered_map<int,int> f; // frequency - dist
        for(int a = 0 ; a<nums.size();a++){
            int i = nums[a];
            // for every number we do this
            if(m[i] > 0){
                f[m[i]]--; 
                if(f[m[i]] == 0) f.erase(m[i]);
            }
            m[i]++;
            f[m[i]]++;
            // what we have to check is that f.size() == 2
            // when to be del when eleminating element must have frq 1 or same or smae + 1
            if(f.size() == 2){ 
                bool flag = 0;
                pair<int,int> a1;
                pair<int,int> a2;
                int c = 0;
                for(auto x: f){ 
                    if(c == 0) a1 = x;
                    else a2 = x;
                    c++;             
                }
                // Now we have 2 pairs in x , so if we have frq diff is 1 then we can check if
                if((a1.first - a2.first) == 1){
                    if(a1.second == 1) flag = 1;
                }else if((a2.first - a1.first) == 1){
                    if(a2.second == 1) flag = 1;
                }
                if((a1.first == 1 && a1.second == 1) || (a2.first == 1 && a2.second == 1)) flag = 1; 
                if(flag) ans = max(ans,a+1);
                // cout<<ans<<endl;
            }
            if(f.size() == 1 && (f.find(1) != f.end() || f.begin()->second == 1)){ ans = max(ans,a+1);}
        }
        return ans;
    }
};