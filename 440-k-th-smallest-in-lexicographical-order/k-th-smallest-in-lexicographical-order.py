class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def count_steps(prefix, n):
            steps = 0
            first = prefix
            last = prefix
            while first <= n:
                steps += min(n, last) - first + 1
                first *= 10
                last = last * 10 + 9
            return steps

        curr = 1
        k -= 1  

        while k > 0:
            steps = count_steps(curr, n)
            if steps <= k:
                
                curr += 1
                k -= steps
            else:
               
                curr *= 10
                k -= 1

        return curr