class Solution {

    public boolean backspaceCompare(String S, String T) {

        return build(S).equals(build(T));

    }

    

    private String build(final String str) {

        Stack<Character> stack = new Stack<>();

        

        for(char c : str.toCharArray()) {

            if(c != '#') {

                stack.push(c);

            }

            else if(!stack.empty()) {

                stack.pop();

            }

        }

        

        return String.valueOf(stack);

    }
}