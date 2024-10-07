class Solution {
    public int minLength(String s) {
        Stack<Character> st = new Stack<Character>();

        for(Character c: s.toCharArray()){
            if( !st.isEmpty() && 
            ((st.peek() == 'A' && c == 'B') || (st.peek() == 'C' && c == 'D')))
                st.pop();
            else
                st.push(c);
        }
        return st.size();
    }
}