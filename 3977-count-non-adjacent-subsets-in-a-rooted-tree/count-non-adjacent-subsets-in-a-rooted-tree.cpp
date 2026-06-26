/**
 * Time Complexity: O(n * k * k)
 * Space Complexity: O(n * k)
 * where `n` is the length of the vector `nums`
 */
class Solution {
 private:
  static constexpr int mod = 1000000007;

  using dp_t = vector<int>;
  using result_t = array<vector<int>, 2>;

 public:
  int countValidSubsets(const vector<int> &parent, const vector<int> &nums, const int k) {
    const int n = static_cast<int>(nums.size());
    vector<int> tree[n];
    for (int c = 1; c < n; ++c) {
      const int p = parent[c];
      tree[p].emplace_back(c);
    }

    const auto [dp0, dp1] = dfs(tree, nums, k, 0);
    return subtract(plus(dp0[0], dp1[0]), 1);
  }

 private:
  int plus(const int a, const int b) {
    return (a + b) % mod;
  }

  int subtract(const int a, const int b) {
    return (mod + a - b) % mod;
  }

  int multiply(const int a, const int b) {
    return static_cast<int>((static_cast<long long>(a) * b) % mod);
  }

  vector<int> merge(const vector<int> &a, const vector<int> &b, const int k) {
    vector<int> ret(k);
    for (int i = 0; i < k; ++i) {
      if (a[i] == 0) {
        continue;
      }
      for (int j = 0; j < k; ++j) {
        if (b[j] == 0) {
          continue;
        }
        const int r = (i + j) % k;
        ret[r] = plus(ret[r], multiply(a[i], b[j]));
      }
    }
    return ret;
  }

  result_t dfs(const vector<int> *tree, const vector<int> &nums, const int k, const int node) {
    vector<int> dp0(k);
    vector<int> dp1(k);
    dp0[0] = 1;
    dp1[nums[node] % k] = 1;
    for (const int child : tree[node]) {
      const auto [cdp0, cdp1] = dfs(tree, nums, k, child);
      vector<int> cdp01(k);
      for (int r = 0; r < k; ++r) {
        cdp01[r] = plus(cdp0[r], cdp1[r]);
      }

      dp0 = merge(dp0, cdp01, k);
      dp1 = merge(dp1, cdp0, k);
    }
    return {dp0, dp1};
  }
};