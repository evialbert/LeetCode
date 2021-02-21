class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        words_set = words.sort(key=len)
        ans = []
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if words[i] in words[j]:
                    ans.append(words[i])
        return set(ans)