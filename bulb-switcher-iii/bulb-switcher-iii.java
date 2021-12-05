class Solution {
    public int numTimesAllBlue(int[] light) {
    
        int count = 1;
        int answer = 0;
        int sum = 0;
         for (int i = 0; i < light.length; i++) {
        sum += light[i];
             if (sum == count) {
                 answer++;
             }
         count += i + 2;
        }
        return answer;
    }
}
