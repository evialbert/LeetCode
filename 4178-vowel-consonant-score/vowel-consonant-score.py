class Solution:
    def vowelConsonantScore(self, s: str) -> int:
        
        vowels_list = ['a','e','i','o','u']
        
        v = 0
        c = 0


        for letter in s:
            if letter in vowels_list:
                v += 1
            elif letter.isalpha(): 
                c += 1


        if c > 0:
            score = math.floor(v/c)
        else:
            score = 0
        
        
        return score