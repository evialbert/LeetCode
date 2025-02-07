class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        def isPalindrome(s):
            return s == s[::-1]

        have = defaultdict(int)
        for (k, w) in enumerate(words):
            have[w] = k

        res = set()
        for (j, w) in enumerate(words):
            for i in range(len(w)+1):
                prefix, suffix = w[:i], w[i:]
                if isPalindrome(prefix) and suffix[::-1] in have:
                    k = have[suffix[::-1]]
                    if j != k:
                        res.add((k, j))
            for i in range(len(w), -1, -1):
                prefix, suffix = w[:i], w[i:len(w)]
                if isPalindrome(suffix) and prefix[::-1] in have:
                    k = have[prefix[::-1]]
                    if j != k:
                        res.add((j, k))
        return [[i, j] for (i, j) in res]


            