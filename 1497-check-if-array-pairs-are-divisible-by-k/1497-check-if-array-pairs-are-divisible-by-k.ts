var canArrange = function(arr, k) {
    const freq = new Array(k).fill(0);
        
        for (const num of arr) {
            let rem = num % k;
            if (rem < 0) {
                rem += k;
            }
            freq[rem]++;
        }
        
        if (freq[0] % 2 !== 0) {
            return false;
        }
        
        for (let i = 1; i <= Math.floor(k / 2); i++) {
            if (freq[i] !== freq[k - i]) {
                return false;
            }
        }
        
        return true;
};