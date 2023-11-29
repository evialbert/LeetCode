class Solution:
    def beautifulSubstrings(self, s: str, k: int) -> int:
        for i in range(1,k+1):
            if i * i % k == 0:
                p = i
                break
        p = 2 * p
        sumdict = {0:{p-1:1}}
        cursum = 0
        vowels = {'a','e','i','o','u'}
        count = 0
        for i in range(len(s)):
            cursum += 1 if s[i] in vowels else -1
            cate = i % p
            if cursum in sumdict:
                if cate in sumdict[cursum]:
                    count += sumdict[cursum][cate]
                    sumdict[cursum][cate] += 1
                else:
                    sumdict[cursum][cate] = 1
            else:
                sumdict[cursum] = {cate:1}

        return count