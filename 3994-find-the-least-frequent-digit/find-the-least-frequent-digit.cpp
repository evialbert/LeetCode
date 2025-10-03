class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> cnt(10);
        while(n) {
            int rem = n % 10;
            cnt[rem]++;
            n /= 10;
        }
        int freq = INT_MAX, num = -1;
        for(int i = 0; i < 10; i++) {
            if(cnt[i] && cnt[i] < freq) {
                num = i;
                freq = cnt[i];
            }
        }
        return num;
    }
};