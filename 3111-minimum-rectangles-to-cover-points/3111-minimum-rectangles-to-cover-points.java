class Solution {
  public int minRectanglesToCoverPoints(int[][] points, int w) {
    Arrays.sort(points, (a,b)-> a[0]-b[0]);
    int count = 1;

    int threshold = points[0][0] + w;
    for (int[] point : points) {
      if (point[0] > threshold) {
        count++;
        threshold = point[0] + w;
      }
    }

    return count;
  }
}