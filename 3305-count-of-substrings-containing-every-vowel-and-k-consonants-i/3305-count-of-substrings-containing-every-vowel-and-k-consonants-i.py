class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        str_dict = {
            "a":0,
            "e":1,
            "i":2,
            "o":3,
            "u":4
        }
        ans = 0
        i = 0
        while i < len(word) - k - 4:
            accessed_ = [0] * 5
            consonant_cnt = 0
            j = i
            ok = 1
            while j < len(word):

                if word[j] in str_dict:
                    accessed_[str_dict[word[j]]] = 1
                else:
                    consonant_cnt += 1
                    if consonant_cnt > k:
                        ok = 0
                        break
                if sum(accessed_) == 5 and consonant_cnt == k:
                    ans += 1
                j += 1

            i =i + 1
        return ans