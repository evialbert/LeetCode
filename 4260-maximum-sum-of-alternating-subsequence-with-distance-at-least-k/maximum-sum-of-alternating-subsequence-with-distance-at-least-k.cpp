/**
 * Time Complexity: O(n * log(num_range))
 * Space Complexity: O(n + num_range)
 * where `n` is the length of the vector `nums`
 *       `num_range` is (`max_num` - `min_num` + 1)
 *       `max_num` is maximum number of the vector `nums`
 *       `min_num` is minimum number of the vector `nums`
 */
class Solution {
 private:
  class FenwickTree {
   public:
    FenwickTree(const int n) : tree_(n) {
    }

    long long read(const int i) {
      long long ret = 0LL;
      for (int index = i; index > 0; index -= index & -index) {
        ret = max(ret, tree_[index - 1]);
      }
      return ret;
    }

    void update(const int i, const long long value) {
      const int n = static_cast<int>(tree_.size());
      for (int index = i; index < n + 1; index += index & -index) {
        tree_[index - 1] = max(tree_[index - 1], value);
      }
    }

   private:
    vector<long long> tree_;
  };

 public:
  long long maxAlternatingSum(const vector<int> &nums, const int k) {
    const int n = static_cast<int>(nums.size());
    const auto mm = minmax_element(nums.begin(), nums.end());
    const int min_num = *mm.first;
    const int max_num = *mm.second;
    const int num_range = max_num - min_num + 1;
    FenwickTree up_tree(num_range);
    FenwickTree down_tree(num_range);
    long long up[n];
    memset(up, 0, sizeof(up));
    long long down[n];
    memset(down, 0, sizeof(down));
    for (int i = 0; i < n; ++i) {
      if (i < k) {
        up[i] = nums[i];
        down[i] = nums[i];
      } else {
        // i >= k
        up_tree.update(max_num - nums[i - k] + 1, up[i - k]);
        down_tree.update(nums[i - k] - min_num + 1, down[i - k]);
        up[i] = nums[i] + down_tree.read(nums[i] - min_num);
        down[i] = nums[i] + up_tree.read(max_num - nums[i]);
      }
    }

    return max(*max_element(up, up + n), *max_element(down, down + n));
  }
};