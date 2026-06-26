class Solution {
private:
    using ll = long long;
    
    ll power(ll base, int exp, ll limit) {
        ll result = 1;
        while(exp--) {
            result *= base;
            if(result > limit) return limit + 1;
        }
        return result;
    }
    
    int lowerBound(int l, int r, int k) {
        int low = 0, high = r, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            ll val = power(mid, k, r);
            
            if(val >= l) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(int l, int r, int k) {
        int low = 0, high = r, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            ll val = power(mid, k, r);
            
            if(val <= r) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
public:
    int countKthRoots(int l, int r, int k) {
        int left = lowerBound(l, r, k);
        int right = upperBound(l, r, k);
        
        if(left == -1 || right == -1 || left > right) return 0;
        
        return right - left + 1;
    }
};