/**
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 * where `n` is the length of the vector `nums`
 */
class Solution {
 private:
  static constexpr int invalid_index = -1;

  class SegmentTree {
   public:
    SegmentTree(const int n)
    : n_(n)
    , max_sums_(tree_size())
    , min_sums_(max_sums_.size())
    , lazy_(max_sums_.size()) {
    }

    void update(const int left, const int right, const int delta) {
      update_impl(0, 0, n_, left, right, delta);
    }

    int find(const int left, const int right, const int value) {
      return find_impl(0, 0, n_, left, right, value);
    }

   private:
    int tree_size() const {
      return (1 << (static_cast<int>(ceil(log2(n_))) + 1)) - 1;
    }

    void update_impl(const int node, const int begin, const int end, const int left, const int right, const int delta) {
      if (left >= end || right <= begin) {
        return;
      }

      if (left <= begin && end <= right) {
        max_sums_[node] += delta;
        min_sums_[node] += delta;
        lazy_[node] += delta;
        return;
      }

      push_down(node, begin, end);

      const int left_node = (node << 1) + 1;
      const int right_node = (node << 1) + 2;
      const int mid = begin + ((end - begin) >> 1);
      update_impl(left_node, begin, mid, left, right, delta);
      update_impl(right_node, mid, end, left, right, delta);
      max_sums_[node] = max(max_sums_[left_node], max_sums_[right_node]);
      min_sums_[node] = min(min_sums_[left_node], min_sums_[right_node]);
    }

    void push_down(const int node, const int begin, const int end) {
      if (lazy_[node] == 0) {
        return;
      }

      const int left_node = (node << 1) + 1;
      const int right_node = (node << 1) + 2;
      
      max_sums_[left_node] += lazy_[node];
      min_sums_[left_node] += lazy_[node];
      lazy_[left_node] += lazy_[node];

      max_sums_[right_node] += lazy_[node];
      min_sums_[right_node] += lazy_[node];
      lazy_[right_node] += lazy_[node];

      lazy_[node] = 0;
    }

    int find_impl(const int node, const int begin, const int end, const int left, const int right, const int value) {
      if (left >= end || right <= begin || value < min_sums_[node] || value > max_sums_[node]) {
        return invalid_index;
      }

      if (end - begin == 1) {
        return begin;
      }

      push_down(node, begin, end);

      const int left_node = (node << 1) + 1;
      const int right_node = (node << 1) + 2;
      const int mid = begin + ((end - begin) >> 1);
      int ret = find_impl(left_node, begin, mid, left, right, value);
      if (ret == invalid_index) {
        ret = find_impl(right_node, mid, end, left, right, value);
      }
      return ret;
    }

    const int n_;
    vector<int> max_sums_;
    vector<int> min_sums_;
    vector<int> lazy_;
  };

 public:
  int longestBalanced(const vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    const auto mm = minmax_element(nums.begin(), nums.end());
    const int min_num = *mm.first;
    const int max_num = *mm.second;
    const int num_range = max_num - min_num + 1;
    SegmentTree segment_tree(n + 1);
    int num_to_index[num_range];
    memset(num_to_index, invalid_index, sizeof(num_to_index));
    int ret = 0;
    for (int sum = 0, i = 1; i < n + 1; ++i) {
      const int num = nums[i - 1];
      const int value = (num & 1) == 0 ? -1 : 1;
      int &pi = num_to_index[num - min_num];
      if (pi == invalid_index) {
        sum += value;
        segment_tree.update(i, n + 1, value);
      } else {
        segment_tree.update(pi, i, -value);
      }
      pi = i;
      const int previous_index = segment_tree.find(0, i - ret, sum);
      if (previous_index != invalid_index) {
        ret = i - previous_index;
      }
    }
    return ret;
  }
};