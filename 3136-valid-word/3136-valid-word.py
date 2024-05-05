class Solution:
    def isValid(self, word: str) -> bool:
        word = word.lower()
        vowels = ["a","e","i","o","u"]
        cons = 0
        vow = 0
        c = len(word)
        for i in word:
            if not i.isalnum():
                return False
            if i in vowels:
                vow +=1
            elif ord(i)>=65 and ord(i)<=90 or ord(i)>=97 and ord(i) < 123:
                cons += 1
            
        if vow and cons and c>2:
            return True
        return False