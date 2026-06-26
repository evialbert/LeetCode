class Solution {
public:
    using ll = long long;

    //computes cost for given vector c, target k and x between 0 and k-1 inclusive
    ll calc(vector<int>& v, int x, int k) {
        ll cost = 0;
        for (int a : v) {
            int r = a % k;
            int d = abs(r - x);
            cost += min(d, k - d);
        }
        return cost;
    }

    int minOperations(vector<int>& nums, int k) {
        vector<int> even, odd;
        //pushback even indices in even array and odd in odd array
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }

        int K = k;
        vector<ll> A(K, 0), B(K, 0); // make two vectors of size k, where A[x] = cost of transforming all indices to even[i]%k = x, basically storing all costs for all possible answer similarly B[x] for odd

        for (int x = 0; x < K; x++) {
            A[x] = calc(even, x, K);
            B[x] = calc(odd, x, K);
        }

        // find best and second best in B 
        ll best1 = LLONG_MAX, best2 = LLONG_MAX;
        int id1 = -1;

        for (int i = 0; i < K; i++) {
            if (B[i] < best1) {
                best2 = best1;
                best1 = B[i];
                id1 = i;
            } else if (B[i] < best2) {
                best2 = B[i];
            }
        }

        ll ans = LLONG_MAX;

        for (int x = 0; x < K; x++) {
            ll bestBExceptX = (x == id1 ? best2 : best1); // for every in x in A we are choosing y for B st y!=x, if x equals the best index in B, then we have to use 2ndbest of B, otherwise we can use best... IMPORTANT we do NOT need secondbest for A because we iterate over all x in A.
            ans = min(ans, A[x] + bestBExceptX);
        }

        return (int)ans;
    }
};