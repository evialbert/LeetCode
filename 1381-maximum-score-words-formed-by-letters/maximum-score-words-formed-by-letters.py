class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        letterCount = [0] * 26
        for l in letters:
            letterCount[ord(l) - ord('a')] += 1
        return self.dfs(words, score, letterCount, 0)

    def dfs(self, words: List[str], score: List[int], letterCount: List[int], index: int) -> int:
        if index == len(words):
            return 0
        skipScore = self.dfs(words, score, letterCount, index + 1)
        wordScore = 0
        newLetterCount = letterCount[:]
        valid = True
        for c in words[index]:
            if newLetterCount[ord(c) - ord('a')] == 0:
                valid = False
                break
            newLetterCount[ord(c) - ord('a')] -= 1
            wordScore += score[ord(c) - ord('a')]
        takeScore = 0
        if valid:
            takeScore = wordScore + self.dfs(words, score, newLetterCount, index + 1)
        return max(skipScore, takeScore)