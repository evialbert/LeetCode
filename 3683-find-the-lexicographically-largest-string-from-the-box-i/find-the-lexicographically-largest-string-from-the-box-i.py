class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word

        target_len = len(word) - numFriends + 1
        max_char = None
        indexes = []
        
        for i, c in enumerate(word):
            if max_char is None or max_char < c:
                max_char = c
                indexes = [i]
            elif c == max_char:
                indexes.append(i)
        max_part = None
        
        for i in indexes:
            curr = word[i : i + target_len]
            if max_part is None or max_part < curr:
                max_part = curr
        return max_part