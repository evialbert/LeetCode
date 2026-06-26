class Solution {
    public int maxTotalValue(int[] value, int[] decay, int m) {
        long low = 1, high = 0;
        for (int v : value) {
            if (v > high) {
                high = v;
            }
        }
        
        long T = 0;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            long count = 0;
            for (int i = 0; i < value.length; i++) {
                if (value[i] >= mid) {
                    count += (value[i] - mid) / decay[i] + 1;
                }
            }
            
            if (count >= m) {
                T = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        long MOD = 1_000_000_007;
        long totalSum = 0;
        long takenCount = 0;
        
        for (int i = 0; i < value.length; i++) {
            if (value[i] > T) {
                long k = (value[i] - (T + 1)) / decay[i] + 1;
                takenCount += k;
                
                long term1 = (k % MOD) * (value[i] % MOD) % MOD;
                long k_k_minus_1;
                if (k % 2 == 0) {
                    k_k_minus_1 = ((k / 2) % MOD) * ((k - 1) % MOD) % MOD;
                } else {
                    k_k_minus_1 = (k % MOD) * (((k - 1) / 2) % MOD) % MOD;
                }
                long term2 = (decay[i] % MOD) * k_k_minus_1 % MOD;
                
                long curSum = (term1 - term2 + MOD) % MOD;
                totalSum = (totalSum + curSum) % MOD;
            }
        }
        
        if (T > 0) {
            long rem = m - takenCount;
            long padSum = (rem % MOD) * (T % MOD) % MOD;
            totalSum = (totalSum + padSum) % MOD;
        }
        
        return (int) totalSum;
    }
}