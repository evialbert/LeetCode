class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        @cache
        def helper(pos, limit, s):
            if pos == len(s):
                return [0, 1]
            max_digit = int(s[pos]) if limit else 1
            res = 0
            cnt = 0
            for digit in range(max_digit + 1):
                
                nxt_limit = (limit and digit == int(s[pos]))
                nxt_res, nxt_cnt = helper(pos + 1, nxt_limit, s)
                res += nxt_res
                if (len(s) - pos) % x == 0 and digit == 1:
                    res += nxt_cnt
                cnt += nxt_cnt
            return res, cnt

        def check_less(n):
            binary_n = bin(n)[2:]
            return helper(0, True, binary_n)[0]

        right = 10 ** 18
        left = 1
        while left < right:
            mid = left + (right - left + 1) // 2
            if check_less(mid) > k:
                right = mid - 1
            else:
                left = mid
        
        return left
