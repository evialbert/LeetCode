/**
 * Time Complexity: O(q + b * n)
 * Space Complexity: O(b * (n + b))
 * where `q` is the length of the vector `queries`
 *       `b` is static_cast<int>(sqrt(q))
 *       `n` is the length of the vector `nums`
 */
class Solution {
 private:
  static constexpr int mod = 1000000007;

 public:
  int xorAfterQueries(vector<int> &nums, const vector<vector<int>> &queries) {
    using range_t = array<int, 2>;
    constexpr int l_i = 0;
    constexpr int r_i = 1;
    constexpr int k_i = 2;
    constexpr int v_i = 3;
    const int n = static_cast<int>(nums.size());
    const int b = static_cast<int>(sqrt(queries.size()));
    vector<vector<int>> diff(b);
    bool need_calculate[b][b];
    memset(need_calculate, 0, sizeof(need_calculate));

    for (const vector<int> &query : queries) {
      const int l = query[l_i];
      const int r = query[r_i];
      const int k = query[k_i];
      const int v = query[v_i];
      if (k < b) {
        need_calculate[k][l % b] = true;
        if (diff[k].empty()) {
          diff[k] = vector<int>(n, 1);
        }
        diff[k][l] = multiply(diff[k][l], v);
        const int right = r - (r - l) % k + k;
        if (right < n) {
          diff[k][right] = multiply(diff[k][right], inv(v));
        }
      } else {
        // use the brute-force
        for (int i = l; i < r + 1; i += k) {
          nums[i] = multiply(nums[i], v);
        }
      }
    }

    for (int k = 1; k < b; ++k) {
      if (diff[k].empty()) {
        continue;
      }
        
      for (int start = 0; start < k; ++start) {
        if (!need_calculate[start]) {
          continue;
        }

        int coefficient = 1;
        for (int i = start; i < n; i += k) {
          coefficient = multiply(coefficient, diff[k][i]);
          nums[i] = multiply(nums[i], coefficient);
        }
      }
    }

    return reduce(nums.begin(), nums.end(), 0, bit_xor());
  }

 private:
  int multiply(const int a, const int b) {
    return static_cast<int>(static_cast<long long>(a) * b % mod);
  }

  int power(const int n, const int p) {
    int ret = 1;
    int base = n;
    for (int pow = p; pow > 0; pow >>= 1) {
      if ((pow & 1) == 1) {
        ret = multiply(ret, base);
      }
      base = multiply(base, base);
    }
    return ret;
  }

  int inv(const int n) {
    return power(n, mod - 2);
  }
};