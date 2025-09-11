class Solution {
 private:
  class XorBasis {
   public:
    XorBasis(const int n) : basis_(n) {
    }

    void insert(const int x) {
      const int n = static_cast<int>(basis_.size());
      for (int cx = x, bit = n - 1; cx > 0; --bit) {
        if (((cx >> bit) & 1) == 1) {
          if (basis_[bit] == 0) {
            basis_[bit] = cx;
            break;
          }
          cx ^= basis_[bit];
        }
      }
    }

    int max_xor() {
      int ret = 0;
      for (auto ritr = basis_.rbegin(); ritr != basis_.rend(); ++ritr) {
        ret = max(ret, ret ^ *ritr);
      }
      return ret;
    }

   private:
    vector<int> basis_;
  };

 public:
  long long maximizeXorAndXor(const vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    const int max_num = *max_element(nums.begin(), nums.end());
    const int bits = get_bits(max_num);

    long long ret = 0;
    const int n_layouts = 1 << n;
    for (int b_layout = 0; b_layout < n_layouts; ++b_layout) {
      int and_b = b_layout == 0 ? 0 : -1;
      int xor_ac = 0;
      int or_ac = 0;
      for (int i = 0; i < n; ++i) {
        if (((b_layout >> i) & 1) == 1) {
          and_b &= nums[i];
        } else {
          xor_ac ^= nums[i];
          or_ac |= nums[i];
        }
      }

      if (static_cast<long long>(and_b) + (static_cast<long long>(or_ac) << 1) - static_cast<long long>(xor_ac) <= ret) {
        continue;
      }

      const int mask = ((1 << bits) - 1) ^ xor_ac;
      XorBasis xor_basis(bits);
      for (int i = 0; i < n; ++i) {
        if (((b_layout >> i) & 1) == 0) {
          const int x = nums[i] & mask;
          xor_basis.insert(x);
        }
      }

      const long long candidate = static_cast<long long>(and_b) + static_cast<long long>(xor_ac) + (static_cast<long long>(xor_basis.max_xor()) << 1);
      ret = max(ret, candidate);
    }
    return ret;
  }

 private:
  int get_bits(const int number) {
    int ret = 0;
    for (int num = number; num > 0; num >>= 1) {
      ++ret;
    }
    return ret;
  }
};