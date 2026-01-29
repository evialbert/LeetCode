class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        from functools import lru_cache

        def solve(x: int) -> int:
            s = str(x)

            @lru_cache(None)
            def dfs(pos, tight, started, prev_prev, prev):
                # returns (total_waviness, count)
                if pos == len(s):
                    return (0, 1) if started else (0, 0)

                limit = int(s[pos]) if tight else 9
                total_wave = 0
                total_count = 0

                for d in range(0, limit + 1):
                    ntight = tight and d == limit

                    if not started and d == 0:
                        w, c = dfs(pos + 1, ntight, False, -1, -1)
                    else:
                        add = 0
                        if prev_prev != -1:
                            if prev > prev_prev and prev > d:
                                add = 1
                            elif prev < prev_prev and prev < d:
                                add = 1

                        w, c = dfs(pos + 1, ntight, True, prev, d)
                        w += add * c

                    total_wave += w
                    total_count += c

                return total_wave, total_count

            return dfs(0, True, False, -1, -1)[0]

        return solve(num2) - solve(num1 - 1)