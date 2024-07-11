class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        
        for char in s:
            if char == ')':
                temp = []
                # Pop until we find an opening bracket '('
                while stack and stack[-1] != '(':
                    temp.append(stack.pop())
                # Remove the opening bracket '('
                if stack: stack.pop()
                # Push the reversed substring back onto the stack
                stack.extend(temp)
            else:
                stack.append(char)
        
        # Join all characters in the stack to form the final result
        return ''.join(stack)