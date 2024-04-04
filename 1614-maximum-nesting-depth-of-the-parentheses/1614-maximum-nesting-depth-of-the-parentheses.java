class Solution {
    public int maxDepth(String s) {
        int count = 0;
        int depth = 0;
        for(char ch : s.toCharArray()) {
            if(ch == '(') {
                count++;
            } else if(ch == ')') {
                depth = Integer.max(depth, count--);
            }
        }
        return depth;
    }
}