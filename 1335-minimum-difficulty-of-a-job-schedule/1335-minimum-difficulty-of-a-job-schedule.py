class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        @cache
        def go(i, day):
            if i == len(jobDifficulty):
                return 0 if day == d+1 else +inf
            if day == d+1:
                return +inf
            res = +inf
            day_difficulty = -inf
            for j in range(i, len(jobDifficulty)):
                day_difficulty = max(day_difficulty, jobDifficulty[j])
                res = min(res, day_difficulty + go(j+1, day+1))
            return res
        ans = go(0, 1)
        return ans if ans != +inf else -1