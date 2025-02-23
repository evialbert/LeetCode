class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last_occurrence = {char: i for i, char in enumerate(s)}
        stack = []
        visited = set()
    
        for i, char in enumerate(s):
        
            if char in visited:
                continue
       
            while stack and char < stack[-1] and i < last_occurrence[stack[-1]]:
                visited.remove(stack.pop())
            stack.append(char)
            visited.add(char)
    
        return ''.join(stack)