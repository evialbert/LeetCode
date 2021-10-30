class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Character> extraParens = collectExtraParentheses(s, new Stack<Character>()); 
        return removeAllExtraParentheses(extraParens, new StringBuffer(s));
    }
    
    boolean isOpenParen(char c) { return c == '('; }
    
    boolean isCloseParen(char c) { return c == ')'; }
    
    Stack<Character> collectExtraParentheses(String s, Stack<Character> parens) {
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i); 
            if (isOpenParen(c)) {
                parens.push(c);
            } else if (isCloseParen(c)) {
                if (!parens.isEmpty() && isOpenParen(parens.peek())) {
                    parens.pop();
                } else {
                    parens.push(c); 
                }
            }
        }
        return parens;
    }
    
    String removeAllExtraParentheses(Stack<Character> parens, StringBuffer sb) {
        while (!parens.isEmpty()) {
            String paren = String.valueOf(parens.peek());
            if (isOpenParen(parens.pop())) {
                int lastIdx = sb.lastIndexOf(paren);
                sb.delete(lastIdx, lastIdx + 1);
            } else {
                int firstIdx = sb.indexOf(paren);
                sb.delete(firstIdx, firstIdx + 1);
            }
        }
        return sb.toString();
    }
}