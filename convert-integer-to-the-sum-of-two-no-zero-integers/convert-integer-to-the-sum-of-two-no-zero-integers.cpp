class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    auto valid = [](int x) {
      if (!x) return false;
      while (x) {
        if (x % 10 == 0) return false;
        x /= 10;
      }
      return true;
    };
    
    for (int i = 1; i <= n / 2; ++i)
      if (valid(i) && valid(n - i)) 
        return {i, n - i};
    return {};
  }
};