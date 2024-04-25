class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        return (cnt := Counter(word)) and sum(chr(ord(ch)+32) in cnt for ch in cnt)