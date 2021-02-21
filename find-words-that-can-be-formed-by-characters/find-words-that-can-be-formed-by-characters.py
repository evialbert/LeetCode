class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res = 0
        for w in words:
            for l in w:
                if l not in chars or w.count(l) > chars.count(l):
                    break
            else: res += len(w)
        return res