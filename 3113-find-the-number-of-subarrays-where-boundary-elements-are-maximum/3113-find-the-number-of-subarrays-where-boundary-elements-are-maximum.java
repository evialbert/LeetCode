class Solution {
    static class Pair {
        int num;
        long count;

        public Pair(int num, int count) {
            this.num = num;
            this.count = count;
        }
    }

    public long numberOfSubarrays(int[] nums) {
        Stack<Pair> s = new Stack<>();
        long count = nums.length;
        for (int n: nums) {
            while (!s.isEmpty() && s.peek().num < n) {
                s.pop();
            }
            if (!s.isEmpty() && s.peek().num == n) {
                s.peek().count++;
                count += s.peek().count - 1;
            } else {
                s.add(new Pair(n, 1));
            }
        }
        return count;
    }
}