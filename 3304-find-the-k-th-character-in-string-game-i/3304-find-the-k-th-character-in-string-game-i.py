class Solution:
    def kthCharacter(self, k: int) -> str:
        word = 'a'
        while len(word) < k:
            new_word = ''
            for char in word:
                next_char = chr(ord(char) + 1) if char != 'z' else 'a'
                new_word += next_char
            word += new_word
        
        return word[k - 1]