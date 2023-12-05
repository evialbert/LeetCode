class Solution:
    def countCompleteSubstrings(self, word, k):
        pl = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
        hv, cs, res, M, ch, badi  = [0]*len(word), [], 0, 10**9+7, 1, -1
        pk, pj = [(j**k) % M for j in pl], ord(word[0])
        for i, w in enumerate(word):
            j = ord(w) - 97
            if i and abs(j-pj) > 2: badi = i-1
            if j in cs: cs.remove(j)
            cs.append(j)
            ch, pj = (ch*pl[j]) % M, j
            hv[i], ii, tch = ch, i, 1
            if i < k-1: continue
            for j in cs[::-1]:
                ii -= k
                if ii < -1 or ii < badi: break 
                tch = (tch *pk[j]) % M
                base = 1 if ii == -1 else hv[ii]
                if ((base*tch) % M)  == hv[i]: res += 1
        return res   