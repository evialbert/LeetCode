class Solution {
public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    int ans = 10000;  // Initialize ans to a large value

    // Create a 2D vector f to store the minimum operations
    vector<vector<int>> f(n, vector<int>(m + 10, 10000));

    f[0][m] = 0;  // Base case: No changes needed for the first element
    for (int i = 0; i < m; ++i)
      f[0][i] = i + 1;  // Base case: Change the first element to arr2[j] (1 <= j <= m)

    sort(arr2.begin(), arr2.end());  // Sort arr2 in ascending order
    m = unique(arr2.begin(), arr2.end()) - arr2.begin();  // Remove duplicate elements in arr2 and update m

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        // If arr1[i] is changed to arr2[j], find f[i-1][j-1] where arr2[j-1] is exactly smaller than arr2[j]
        if (j != 0)
          f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);

        // Also, check f[i-1][m] where arr1[i-1] < arr2[j]
        if (arr1[i - 1] < arr2[j])
          f[i][j] = min(f[i][j], f[i - 1][m] + 1);
      }

      // If arr1[i] doesn't change
      for (int j = 0; j < m; ++j) {
        if (arr1[i] > arr2[j])
          f[i][m] = min(f[i][m], f[i - 1][j]);
      }

      // Check f[i-1][m] where arr1[i] > arr1[i-1]
      if (arr1[i] > arr1[i - 1])
        f[i][m] = min(f[i][m], f[i - 1][m]);
    }

    // Find the minimum number of operations by checking the last row of f
    for (int i = 0; i <= m; ++i) {
      ans = min(ans, f[n - 1][i]);
    }

    if (ans == 10000)
      return -1;  // If ans is still the initial large value, return -1
    else
      return ans;  // Otherwise, return the minimum number of operations
  }
};