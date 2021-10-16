class Solution {
    StringBuilder sb = new StringBuilder();
    
    class Elem{
        char c;
        int freq;
        Elem(char y, int x){
            this.c = y;
            this.freq = x;
        }
        public String toString(){
            return "{" + this.c + ","+ this.freq + "}";
        }
    }
    
    public String removeDuplicates(String s, int k) {
        Stack<Elem> st = new Stack<>();
        for (char c: s.toCharArray()){
            if(!st.isEmpty() && st.peek().c == c){
                st.push(new Elem(c, st.peek().freq + 1));
            } else {
                st.push(new Elem(c, 1));
            }
            
            if (st.peek().freq == k){
                int temp = k;
                while (temp > 0){
                    st.pop();
                    temp--;
                }
            }
        }
        
        while (!st.isEmpty()){
            sb.append(st.pop().c);
        }
        return sb.reverse().toString();
    }
}