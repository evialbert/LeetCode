class Solution {
    public int numFriendRequests(int[] ages) {
    if (ages.length == 1) {
      return 0;
    }
    int total = 0;
    Arrays.sort(ages);
    int count = 1;
    int res = 0;
    for (int i = 1; i < ages.length; i++) {
      if (ages[i] == ages[i - 1] && (ages[i] > (0.5 * ages[i]) + 7)) {
        res = res + count++;
      } else {
        total = total + res;
        count = 1;
        res = 0;
      }
    }
    if (ages[ages.length - 2] == ages[ages.length - 1]) {
      total = total + res;
    }
    int[] gr = greater(ages);
    for (int i = 0; i < gr.length; i++) {
      total += gr[i];
    }
    return total;
  }

  int countGreater(int arr[], int end, int num) {
    int left = 0;
    int right = end;
    int leftGreater = end + 1;
    while (left <= right) {
      int m = left + (right - left) / 2;
      if (arr[m] > num) {
        leftGreater = m;
        right = m - 1;
      } else {
        left = m + 1;
      }
    }
    return (end - leftGreater + 1);
  }

  private int[] greater(int[] arr) {
    int[] res = new int[arr.length];
    for (int j = arr.length - 1; j >= 0; j--) {
      res[j] = countGreater(arr, j - 1, (int) ((arr[j] * .5) + 7));
    }
    return res;
  }
}