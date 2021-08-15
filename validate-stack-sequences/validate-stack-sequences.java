class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack();
        
        int index = 0;
        for(int i = 0 ;i < pushed.length; i++){    
            stack.push(pushed[i]);  
            while(!stack.isEmpty() && index < pushed.length && stack.peek() == popped[index]){
                    stack.pop();
                    index++;
            }
        }
        return stack.isEmpty() ? true : false;
    }
}