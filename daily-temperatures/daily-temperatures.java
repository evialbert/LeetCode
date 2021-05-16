class Solution {
   public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < T.length; i++) {
            while (!st.empty() && T[i] > T[st.peek()])
                ans[st.peek()] = i - st.pop();
            st.push(i);
        }
        return ans; 
    }
}