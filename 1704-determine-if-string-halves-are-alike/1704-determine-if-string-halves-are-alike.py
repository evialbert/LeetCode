class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = {"A", "E", "I", "O", "U", "a", "e", "i", "o", "u"}
        count = 0
        i = 0
        while(i < len(s) - 1 - i):
            if s[i] in vowels:
                count += 1
            if s[len(s) - 1 - i] in vowels:
                count -= 1
            i += 1
        return True if count == 0 else False