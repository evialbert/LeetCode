class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        def form(cnt):
            n9 = cnt[1] // 2
            n8 = cnt[0] // 3
            n7 = cnt[3]
            n6 = min(cnt[0] % 3, cnt[1] % 2)
            n5 = cnt[2]
            n4 = (cnt[0] % 3 - n6) // 2
            n3 = cnt[1] % 2 - n6
            n2 = cnt[0] % 3 - n6 - 2 * n4
            return ''.join(['2'] * n2 + ['3'] * n3 + ['4'] * n4 +
                   ['5'] * n5 + ['6'] * n6 + ['7'] * n7 +
                   ['8'] * n8 + ['9'] * n9)
        
        cnt = [0] * 4
        for i, v in enumerate([2, 3, 5, 7]):
            while t % v == 0:
                cnt[i] += 1
                t //= v
        if t > 1:
            return "-1"
        n = len(num)
        ds = [
            [0, 0, 0, 0],
            [0, 0, 0, 0],
            [1, 0, 0, 0],
            [0, 1, 0, 0],
            [2, 0, 0, 0],
            [0, 0, 1, 0],
            [1, 1, 0, 0],
            [0, 0, 0, 1],
            [3, 0, 0, 0],
            [0, 2, 0, 0]
        ]

        s = form(cnt[:])     
        if len(s) > len(num) or len(s) == len(num) and s > num:
            return s
        
        for i in range(n):
            if num[i] == '0':
                num = num[:i] + '1' * (n - i)
                break

        ps = [[0]*4 for _ in range(n)]
        for i in range(n):
            for j in range(4):
                ps[i][j] = ds[int(num[i])][j]
        for i in range(1, n):
            for j in range(4):
                ps[i][j] += ps[i-1][j]
        
        if all(ps[-1][i] >= cnt[i] for i in range(4)):
            return num

        for i in range(n-1, -1, -1):
            if num[i] == '9':
                continue
            cb = ps[i-1][:] if i > 0 else [0] * 4
            for j in range(int(num[i]) + 1, 10):
                cx = [max(cnt[k] - cb[k], 0) for k in range(4)]
                # print(cx, ds[j])
                for k in range(4):
                    cx[k] = max(cx[k] - ds[j][k], 0)
                # print(cnt, cb, j, cx, fl(cx[:]), form(cx[:]))
                r = form(cx[:])
                if len(r) <= n - 1 - i:
                    return num[:i] + str(j) + ('1' * (n - 1 - i - len(r)) + r)

        return '1' * (n + 1 - len(s)) + s