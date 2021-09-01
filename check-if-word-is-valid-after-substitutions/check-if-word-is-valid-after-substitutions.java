class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack=new Stack<>();
        for(int i=s.length()-1;i>=0;--i){
            char temp=s.charAt(i);
            if(temp=='a'){
                if(stack.isEmpty() || stack.peek()!='b') return false;
                stack.pop();
                if(stack.isEmpty() || stack.peek()!='c') return false;
                stack.pop();
            }
            else stack.push(temp);
        }
        return stack.isEmpty();
    }
}