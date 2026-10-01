class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for bracket in s:
            if bracket == "{" or bracket == "(" or bracket == "[":
                stack.append(bracket)

            else:
                if len(stack) == 0:
                    return False

                if bracket == "}":
                    if stack[-1] == "{":
                        stack.pop()
                        continue
                
                if bracket == ")":
                    if stack[-1] == "(":
                        stack.pop()
                        continue

                if bracket == "]":
                    if stack[-1] == "[":
                        stack.pop()
                        continue

                return False

        if len(stack) != 0:
            return False
        return True