class Solution {
public:

    int maxScore(vector<int>& nums, int maxVal) {

        sort(nums.begin(), nums.end());
        int maxNum = max(maxVal, nums.back());
        vector<vector<int>> pf(maxNum + 1);
        vector<int> freq(maxNum + 1);
        vector<int> of(maxNum + 1);

        for(int i = 2; i <= maxNum; i ++) {
            int it = i;
            vector<int> pr = {};
            int lim = sqrt(i);

            for(int k = 2; k <= lim; k ++) {
                if(it % k == 0) {
                    pr.push_back(k);
                    while(it > 1 && it % k == 0) {
                        it /= k;
                    }
                }
            }
            if(it > 1) {
                pr.push_back(it);
            }
            pf[i] = pr;
        }

        for(auto it:nums) {
            of[it] ++;
            int lim = sqrt(it);

            for(int k = 1; k <= lim; k ++) {
                if(it % k == 0) {
                    int f1 = k;
                    int f2 = it / k;
                    if(f1 > 1) {
                        freq[f1] ++;
                    }
                    
                    if(f2 > 1 && f1 != f2) freq[f2] ++;
                }
            }
        }

        int ans = 0;
        
        for(int i = maxNum; i >= 1; i --) {
            if(i > maxVal && of[i] == 0) continue;

            vector<int> rep = pf[i];

            int k = rep.size();
            int n = nums.size();
            int cp = n;

            for(int j = 0; j < (1 << k); j ++) {
                int z = 0;
                int p = 1;

                for(int l = 0; l < k; l ++) {
                    if((1 << l) & j) {
                        p *= rep[l];
                        z += 1;
                    }
                }

                int mult = -1;
                if(z % 2 == 0) {
                    mult = 1;
                }
                cp += mult * freq[p];
            }

            cp = n - cp; // number of elements with any matching primes.

            int modifications_needed = max(0, cp - 1);

            

            if(of[i] == 0) {
                modifications_needed ++;
            }

            // cout << i << " " << cp << " " << modifications_needed << " " << of[i] << endl;
            ans = max(ans, i - modifications_needed);
        }

        return ans;
    }
};