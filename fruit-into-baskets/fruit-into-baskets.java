class Solution {
    public int totalFruit(int[] fruits) {
        int max = -1;
        int n1 = fruits[0];
        int n2 = -1;
        int count = 1;
        int pos = 0;
        for(int i=1; i<fruits.length; i++) {
            if(fruits[i] == n1) {
                count++;
            } else if(n2 == -1) {
                n2 = fruits[i];
                count++;
            } else if(fruits[i] == n2) {
                count++;
            } else {
                max = Math.max(max, count);
                count = i - pos + 1;
                n1 = fruits[i-1];
                n2 = fruits[i];
            }
            if(fruits[i] != fruits[i-1])
                pos = i;
        }
        max = Math.max(max, count);
        return max;
    }
}