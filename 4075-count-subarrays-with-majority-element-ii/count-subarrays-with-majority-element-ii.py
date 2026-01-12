class Solution:
    def countMajoritySubarrays(self, nums: list[int], target: int) -> int:
        def update(i):
            while i <= m:
                bits[i] += 1
                i += i&-i

        def query(i):
            s = 0
            while i > 0:
                s += bits[i]
                i -= i&-i
            return s

        n = len(nums)
        arr = [1 if x == target else -1 for x in nums]
        prefix = [0]
        for x in arr:
            prefix.append(prefix[-1] + x)
        vals = sorted(set(prefix))
        idx = {v: i+1 for i, v in enumerate(vals)}
        m = len(vals)
        bits = [0]*(m+1)
        ans = 0
        for p in prefix:
            k = idx[p]
            ans += query(k-1)
            update(k)
        return ans