class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        self.ans = ''
        l = len(s)
        

        def helper(k, ln, pos):
            if ln == 0:
                return
            prev = 0
            for i, j in enumerate(self.ar):
                if j == 0:
                    continue
                low = prev + 1
                req = (pos *  j) // ln
                high = prev + req
                if low <= k <= high:
                    self.ans += chr(i + 97)
                    self.ar[i] -= 1
                    return helper(k - prev, ln - 1, req)
                prev = high
            return



        hold = Counter(s)
        self.ar = [0] * 26
        extra = None
        for i in hold.items():
            (ch, val) = i
            if val % 2 != 0:
                extra = ch
                val -= 1
            val = val // 2
            self.ar[ord(ch) - 97] += val
        reql = l // 2
        fact = [0] * (reql + 1)
        fact[0] = 1
        for i in range(1, len(fact)):
            fact[i] = i * fact[i - 1]
        total_pos = fact[reql]
        for i in self.ar:
            total_pos //= fact[i]
        if k > total_pos:
            return ''
        helper(k, reql, total_pos)
        req = self.ans
        if extra != None:
            return req + extra + req[::-1]
        return req + req[::-1]
            
            
        