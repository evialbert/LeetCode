class Solution:
    # if word is less than or equal 8 - >
    # then every character is one press
    # get count of each word 
    # Create map of char to max frequency
    # once it goes beyond 0-7 -> 1
    # 8-15 -> 2 press per char
    # 16-24 -> 3 presess per char
    # 24-27 -> 4 press per char  

    def minimumPushes(self, word: str) -> int:
        l = len(word)
        return min(8, l) + min(max(0, l - 8), 8) * 2 + min(max(0, l - 16), 8) * 3 + max(0, l - 24) * 4
