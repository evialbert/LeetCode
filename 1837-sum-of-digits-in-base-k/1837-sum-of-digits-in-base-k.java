class Solution {
    public int sumBase(int n, int k) {
        String num = n + "";
        int x = Integer.parseInt(Integer.toString(Integer.parseInt(num, 10), k));
        int sum = 0;
        while (x > 0){
            sum += x % 10;
            x = x / 10;
        }
        return sum;
    }
}