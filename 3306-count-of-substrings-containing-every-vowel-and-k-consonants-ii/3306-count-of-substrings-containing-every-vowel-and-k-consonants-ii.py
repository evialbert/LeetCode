class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:

        vowel = {c:0 for c in "aeiou"}
        v = {c:0 for c in "aeiou"}
        c = 0
        cons = 0
        i = 0
        minwind = 0
        ans = 0
        for j, char in enumerate(word):
            if char in vowel:
                vowel[char] += 1
                v[char] += 1
            else:
                cons += 1
                c += 1

            while cons > k:
                if word[i] in vowel:
                    vowel[word[i]] -= 1
                    if i == minwind:
                        v[word[i]] -= 1
                else:
                    cons -= 1
                    if i == minwind:
                        c -= 1
                if i == minwind:
                    minwind += 1
                i += 1
                
            # print(ans, cons, vowel, char)
            if cons == k and all(val > 0 for val in vowel.values()):
                
                while c == k and all(val > 0 for val in v.values()):
                    if word[minwind] in vowel:
                        v[word[minwind]] -= 1
                    else:
                        c -= 1
                    minwind += 1
                
                ans += minwind - i

        return ans