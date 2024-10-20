class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        operators = []
        result = None
        for ch in expression:
            if ch==",":
                continue
            if ch=='|' or ch=="&" or ch=="!":
                operators.append(ch)
            else:
                result = None 
                if ch == 'f':
                    stack.append(False)
                elif ch=="t":
                    stack.append(True)
                elif ch=="(":
                    stack.append(ch)
                elif ch == ')':
                    var = stack.pop()
                    op = operators.pop()
                    while var != "(":
                        if result == None:
                            result = var
                        else:
                            if op == "|":
                                result = result or var
                            else:
                                result = result and var
                        var = stack.pop()
                    if op == "!":
                        result = not result
                    stack.append(result)
        return stack[0]
