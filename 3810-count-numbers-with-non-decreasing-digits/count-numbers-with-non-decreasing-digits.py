from functools import cache


class Solution:
    def countNumbers(self, l: str, r: str, b: int) -> int:
        MOD = int(1e9)+7
        def to_base(n: int, base: int) -> str:
            if n == 0:
                return "0"
            digits = "0123456789"
            result = []
            n = abs(n)

            while n:
                result.append(digits[n % base])
                n //= base

            return ''.join(reversed(result))

        # convert current deci to b base
        l = to_base(int(l)-1, b)
        r = to_base(int(r), b)

        # Then just do DP
        @cache
        def solve(idx, prev_num, prev_match, upto_num) -> int:
            if idx > len(upto_num):
                return 0
            elif idx == len(upto_num):
                return 1

            ret = 0
            for i in range(prev_num, b):
                # when all match so far and curr will match too
                if i == int(upto_num[idx]) and prev_match:
                    ret += solve(idx + 1, i,prev_match, upto_num)
                # when not match in any prev then any number can go in.
                elif i > int(upto_num[idx]) and not prev_match:
                    ret += solve(idx + 1, i,prev_match, upto_num)
                elif i <= int(upto_num[idx]):
                    ret += solve(idx+1, i,False ,upto_num)
                ret %= MOD
            return ret

        # get both for l and r then subtract count of l to r
        return ((solve(0, 0,True, r) -
                solve(0, 0,True, l)) + MOD) % MOD