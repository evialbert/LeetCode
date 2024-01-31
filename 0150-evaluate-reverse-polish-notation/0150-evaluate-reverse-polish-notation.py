class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i[-1].isdigit():
                stack.append(int(i))
            else:
                o2 = stack.pop() 
                o1 = stack.pop()
                if i == '+': 
                    stack.append(o1 + o2)
                elif i == '-': 
                    stack.append(o1 - o2)
                elif i == '*': 
                    stack.append(o1 * o2)
                else: 
                    stack.append(int(float(o1) / o2))
        return stack.pop()