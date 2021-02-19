class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        stack = [ ]
        toks = path.split("/")
        stack.append(toks[0])
        toks = toks[1:]
        for tok in toks:
            if tok in ("", "."):
                continue
            elif ".." ==  tok:
                if len(stack) > 0 and "" != stack[len(stack) - 1]:   # root / should not be poped to distinguish abs path and rel path
                    stack.pop()
                #else:
                #    return ""         # /home/../../..
            else:
                stack.append(tok)
        len_stack = len(stack)
        if len_stack >1:
            return "/".join(stack) if "" == stack[0] else "/" + "/".join(stack)
        elif (1 == len_stack and "" == stack[0]) or 0 == len_stack:
            return "/"