class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        W = []
        for word in words:
            smallest_char = min(word)
            c = collections.Counter(word)

            W.append(c[smallest_char])

        result = []
        for q in queries:
            smallest_char = min(q)
            c = collections.Counter(q)
            smallest_freq = c[smallest_char]

            count = 0
            for w in W:
                if smallest_freq < w:
                    count += 1
            result.append(count)

        return result