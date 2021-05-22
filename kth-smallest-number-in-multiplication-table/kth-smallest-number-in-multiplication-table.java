class Solution {
  public int findKthNumber(int m, int n, int k) {
        int l = 1;
        int h = m * n;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int smallerOrEqualsMidCount = getSmallerOrEqualsCount(m, n, mid);
            if (smallerOrEqualsMidCount >= k) h = mid - 1; // Choose left half
            else l = mid + 1; // Choose right half
        }
        return l; // We found the element. h passed it. l is still on the element. We stop when h<l, default h=mid-1.
    }

    private int getSmallerOrEqualsCount(int m, int n, int x) { // Find the number of smaller or equals x in the table.
        int count = 0;
        for (int i = 1; i <= m; i++) {
            int smallerOrEqualsInMidRow = x / i;
            count += Math.min(n, smallerOrEqualsInMidRow); // In the rows which include x, don't add all n columns.
        }
        return count;
    }
}