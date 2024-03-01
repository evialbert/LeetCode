class Solution:
    def earliestSecondToMarkIndices(self, A: List[int], B: List[int]) -> int:
        firsts = {}
        for i, b in enumerate(B):
            if A[b - 1]:
                firsts.setdefault(b, i)

        first_to_val = {i: A[b-1] for b, i in firsts.items()}

        n = len(A)
        tot = n + sum(A)
        dp = [0] * (n + 1)
        for i in range(len(B)):
            val = first_to_val.get(i, 0)

            cur = [x + 1 for x in dp]
            if val:
                for j in range(n):
                    cur[j+1] = dp[j] + val + 1
            for j in range(n):
                cur[j] = max(cur[j], dp[j+1])
            dp = cur

            if tot <= dp[0]:
                return i + 1

        return -1