class Solution {
public:
    const int MOD = 1e9 + 7;
    const int mod = 1e9 + 7;
    long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
       
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        int maxi = 0;
        int maxin;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            if (maxi <= nums[i]) {
                maxin = i;
                maxi = nums[i];
            }
        }
        
        if(m==1)return nums;
        
        while (k--) {
            long long v = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            v = (v * m);
            pq.push({v, ind});
            if (ind == maxin) {
                break;
            }
        }
        int mul;
        int mo;
        if(k<=0){
             mul=0;
             mo=0;
        }else{
            mul = k / nums.size();
            mo = k % nums.size();
        }
        
        unordered_map<int,int>mp;
        vector<long long> v1(nums.size()); 
        while (!pq.empty()){
            long long x = pq.top().first, y = pq.top().second;
            v1[y] = x;
            pq.pop();
        }
        for (int i = 0; i < nums.size(); i++) pq.push({v1[i],i});
         while (!pq.empty()){
            int x = pq.top().second;
            mp[x] = mul;
            if (mo > 0)mp[x]++,mo--;
            pq.pop();
        }
     
        for (int i = 0; i < nums.size(); i++){
            long long mlt = power_mod(m, mp[i],mod);
            v1[i] = ((v1[i]%mod)*(mlt%mod))%mod;
            nums[i] = v1[i];
        }
        return nums;
    }
};