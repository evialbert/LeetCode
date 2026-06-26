class Solution:
    def maximumSum(self, nums: List[int], m: int, l: int, r: int) -> int:
        fentoluric = (nums, m, l, r)

        n = len(nums)
        pref = [0] * (n + 1)

        for i in range(n):
            pref[i + 1] = pref[i] + nums[i]

        def best_single():
            dq = deque()
            best = -10**30

            for i in range(1, n + 1):
                j = i - l

                if j >= 0:
                    while dq and dq[-1][1] >= pref[j]:
                        dq.pop()
                    dq.append((j, pref[j]))

                while dq and dq[0][0] < i - r:
                    dq.popleft()

                if dq:
                    best = max(best, pref[i] - dq[0][1])

            return best

        single = best_single()

        def check(cost):
            dp_val = [0] * (n + 1)
            dp_cnt = [0] * (n + 1)
            dq = deque()

            for i in range(1, n + 1):
                j = i - l

                if j >= 0:
                    val = dp_val[j] - pref[j]
                    cnt = dp_cnt[j]

                    while dq and (dq[-1][1] < val or (dq[-1][1] == val and dq[-1][2] >= cnt)):
                        dq.pop()

                    dq.append((j, val, cnt))

                while dq and dq[0][0] < i - r:
                    dq.popleft()

                dp_val[i] = dp_val[i - 1]
                dp_cnt[i] = dp_cnt[i - 1]

                if dq:
                    val = pref[i] - cost + dq[0][1]
                    cnt = dq[0][2] + 1

                    if val > dp_val[i] or (val == dp_val[i] and cnt < dp_cnt[i]):
                        dp_val[i] = val
                        dp_cnt[i] = cnt

            return dp_val[n], dp_cnt[n]

        val, cnt = check(0)

        if cnt <= m:
            return val if cnt > 0 else single

        low, high = 0, sum(abs(x) for x in nums) + 1

        while low < high:
            mid = (low + high) // 2
            val, cnt = check(mid)

            if cnt > m:
                low = mid + 1
            else:
                high = mid

        cost = low
        val, cnt = check(cost)

        return max(single, val + cost * m)      