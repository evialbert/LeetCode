class Solution:
    def makeFancyString(self, s: str) -> str:
        word = list(s)
        cnt = 1
        res = [s[0]]
        curr = s[0]

        for i in range(1, len(word)):
            if curr == word[i]:
                cnt += 1
            else:
                curr = word[i]
                cnt = 1
            
            if cnt >= 3:
                    continue
            res.append(curr)
        
        return "".join(res)