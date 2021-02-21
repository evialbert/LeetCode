class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        for word in words:
            if word.startswith(searchWord):
                return words.index(word) + 1
        return -1