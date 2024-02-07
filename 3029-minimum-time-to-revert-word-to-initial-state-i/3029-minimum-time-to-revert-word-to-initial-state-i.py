class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        count = 0
        temp = word
        def isEqual(cur, original):
            for i in range(len(cur)):
                if cur[i] != original[i]:
                    return False
            return True
        while True:
            count += 1
            temp = word[count*k:]
            if isEqual(temp, word):
                break
        return count
        