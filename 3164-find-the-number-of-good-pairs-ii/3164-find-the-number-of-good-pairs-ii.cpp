class Solution {
    private:
        long long solver(vector<int>& nums1, vector<int>& nums2, int k)
        {
            map<int,int> mp;
            int n = nums1.size();
            int m = nums2.size();
            int mx = 0;
            for(int i = 0;i < n;++i){
                mx = max(mx,nums1[i]);
                mp[nums1[i]]++;
            }
            map<int,int> mp2,mp3;
            for(int i = 0;i < m;++i){
                mp2[nums2[i]]++;
            }
            long long ans = 0;
            for(int i = 0;i < m;++i){
                if (mp3.find(nums2[i]) == mp3.end()){
                    for(int j = nums2[i];j <= mx;j += nums2[i]){
                        if (mp.find(j) != mp.end()){
                            long long p = mp[j];
                            p = p*mp2[nums2[i]];
                            ans += p;
                        }
                    }
                    mp3[nums2[i]] = 1;
                }
            }
            return ans;
        }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        for(int i = 0;i < nums2.size();++i){
            nums2[i] = nums2[i] * k;
        }
        return solver(nums1,nums2,k);
    }
};