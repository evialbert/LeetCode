class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        return word[i::-1] + word[(i + 1):] if (i := word.find(ch)) != -1 else word