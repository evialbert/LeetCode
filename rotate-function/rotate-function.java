class Solution {
  public int maxRotateFunction(int[] A) {
        int sum = 0, total = 0, max = 0;
        for(int i = 0; i < A.length; i++) {
            sum += i * A[i];
            total += A[i];
        }
        max = sum;
        //System.out.println("sum="+sum+" total="+total);
        int n = A.length;
        for(int i = 1; i < n; i++) {
            int tmp = sum + total - n * A[n - i];
            max = Math.max(max, tmp);
         //   System.out.println("tmp="+tmp);
            sum = tmp;
        }
        return max;
  }
}