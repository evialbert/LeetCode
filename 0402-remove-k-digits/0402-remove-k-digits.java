class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack();
        
        for(int i=0;i<num.length();i++){
            char ch = num.charAt(i);
            while(st.size()>0 && st.peek()>ch && k>0){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        //if less then k digits are removed
        while(k>0){
            st.pop();
            k--;
        }
        
        //creating answer in reverse
        StringBuilder sb = new StringBuilder();
        while(st.size()!=0){
            sb.append(st.pop());
        }
        
        //removing 0's which will be in front
        while(sb.length()>0 && sb.charAt(sb.length()-1)=='0'){
            sb.deleteCharAt(sb.length()-1);
        }
        
        if(sb.length()==0) return "0";
        
        return sb.reverse().toString();
    }
}