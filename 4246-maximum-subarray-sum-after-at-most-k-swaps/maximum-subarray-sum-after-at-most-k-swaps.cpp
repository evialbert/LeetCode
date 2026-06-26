/**
 * Time Complexity: O(n * n * log(n))
 * Space Complexity: O(n)
 * where `n` is the length of the vector `nums`
 */
class Solution {
 private:
  template <typename T>
  class FenwickTree {
   public:
    FenwickTree(const int n) : tree_(n) {
    }

    T read(const int i) const {
      T ret = 0;
      for (int index = i; index > 0; index -= index & -index) {
        ret += tree_[index - 1];
      }
      return ret;
    }

    void update(const int i, const T delta) {
      const int n = static_cast<int>(tree_.size());
      for (int index = i; index < n + 1; index += index & -index) {
        tree_[index - 1] += delta;
      }
    }

    T total() const {
      return read(static_cast<int>(tree_.size()));
    }

    int kth(const T k) const {
      const int n = static_cast<int>(tree_.size());
      int bit_offset = 1;
      while ((bit_offset << 1) < n + 1) {
        bit_offset <<= 1;
      }

      int index = 0;
      T remains = k;
      for (int offset = bit_offset; offset > 0; offset >>= 1) {
        const int next_index = index + offset;
        if (next_index < n + 1 && tree_[next_index - 1] < remains) {
          index = next_index;
          remains -= tree_[next_index - 1];
        }
      }
      return index + 1;
    }

   private:
    vector<T> tree_;
  };

  class OrderedMultiSet {
   public:
    OrderedMultiSet(const vector<int> &sorted, const int n)
    : sorted_(sorted)
    , count_(n)
    , sum_(n) {
    }

    void add(const int rate, const int value) {
      count_.update(rate, 1);
      sum_.update(rate, value);
    }

    void remove(const int rate, const int value) {
      count_.update(rate, -1);
      sum_.update(rate, -value);
    }

    int size() const {
      return count_.total();
    }

    long long total() const {
      return sum_.total();
    }

    int kth_smallest(const int k) const {
      return sorted_[count_.kth(k) - 1];
    }

    int kth_largest(const int k) const {
      const int total_size = size();
      return sorted_[count_.kth(total_size - k + 1) - 1];
    }

    long long sum_smallest(const int k) const {
      if (k <= 0) {
        return 0;
      }

      const int p = count_.kth(k);
      const int before_count = count_.read(p - 1);
      const long long before_sum = sum_.read(p - 1);
      const int need = k - before_count;
      return before_sum + need * sorted_[p - 1];
    }

    long long sum_largest(const int k) const {
      if (k <= 0) {
        return 0;
      }

      const int total_size = size();
      const long long total_sum = total();
      return total_sum - sum_smallest(total_size - k);
    }

   private:
    const vector<int> &sorted_;
    FenwickTree<int> count_;
    FenwickTree<long long> sum_;
  };

 public:
  long long maxSum(const vector<int> &nums, const int k) {
    const int n = static_cast<int>(nums.size());
    int indices[n];
    iota(indices, indices + n, 0);
    sort(indices, indices + n, [&nums](const int lhs, const int rhs) -> bool {
      return nums[lhs] < nums[rhs];
    });
    int index_to_rate[n];
    memset(index_to_rate, 0, sizeof(index_to_rate));
    vector<int> sorted;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || nums[indices[i - 1]] != nums[indices[i]]) {
        sorted.emplace_back(nums[indices[i]]);
      }
      index_to_rate[indices[i]] = static_cast<int>(sorted.size());
    }

    long long ret = numeric_limits<long long>::min();
    for (int l = 0; l < n; ++l) {
      OrderedMultiSet inside(sorted, n);
      OrderedMultiSet outside(sorted, n);
      for (int i = 0; i < n; ++i) {
        outside.add(index_to_rate[i], nums[i]);
      }

      long long cur_sum = 0LL;
      int t = 0;
      for (int r = l; r < n; ++r) {
        cur_sum += nums[r];

        outside.remove(index_to_rate[r], nums[r]);
        inside.add(index_to_rate[r], nums[r]);

        const int inside_length = r - l + 1;
        const int outside_length = n - inside_length;
        const int limit = min({k, inside_length, outside_length});

        t = min(t, limit);
        for (; t > 0; --t) {
          const long long out = outside.kth_largest(t);
          const long long in = inside.kth_smallest(t);
          if (out > in) {
            break;
          }
        }
        for (; t < limit; ++t) {
          const long long out = outside.kth_largest(t + 1);
          const long long in = inside.kth_smallest(t + 1);
          if (out <= in) {
            break;
          }
        }

        const long long gain = outside.sum_largest(t) - inside.sum_smallest(t);
        ret = max(ret, cur_sum + gain);
      }
    }
    return ret;
  }
};