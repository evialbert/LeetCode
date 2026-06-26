class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums2)

        freq1 = {}
        for x in nums1:
            freq1[x] = freq1.get(x, 0) + 1

        vals = list(freq1.keys())
        mult = [freq1[x] for x in vals]

        u = len(vals)

        last_count_query = -1
        count_queries = 0

        for i, q in enumerate(queries):
            if q[0] == 2:
                last_count_query = i
                count_queries += 1

        if last_count_query == -1:
            return []

        update_queries = last_count_query + 1 - count_queries

        if update_queries == 0:
            block_size = n
        else:
            block_size = int(
                (n * (0.08 * update_queries + 0.60 * count_queries * u) / update_queries) ** 0.5
            )

            block_size = max(1, min(n, block_size))

        block_count = (n + block_size - 1) // block_size

        arr = nums2[:]
        lazy = [0] * block_count

        block_freq = []

        for b in range(block_count):
            lo = b * block_size
            hi = min(n, lo + block_size)
            d = {}

            for i in range(lo, hi):
                x = arr[i]
                d[x] = d.get(x, 0) + 1
            block_freq.append(d)

        def add_partial(lo: int, hi:int, val: int) -> None:
            b = lo // block_size
            d = block_freq[b]

            for i in range(lo, hi + 1):
                old = arr[i]

                c = d[old]
                if c == 1:
                    del d[old]
                else:
                    d[old] = c - 1

                new = old + val
                arr[i] = new
                d[new] = d.get(new, 0) + 1

        ans = []
        blocks = range(block_count)

        for q in queries[:last_count_query + 1]:
            if q[0] == 1:
                _, l, r, val = q

                bl = l // block_size
                br = r // block_size

                if bl == br:
                    block_lo = bl * block_size
                    block_hi = min(n, block_lo + block_size) - 1

                    if l == block_lo and r == block_hi:
                        lazy[bl] += val
                    else:
                        add_partial(l, r, val)

                else:
                    left_lo = bl * block_size
                    left_hi = min(n, left_lo + block_size) - 1

                    if l == left_lo:
                        lazy[bl] += val
                    else:
                        add_partial(l, left_hi, val)

                    for b in range(bl + 1, br):
                        lazy[b] += val

                    right_lo = br * block_size
                    right_hi = min(n, right_lo + block_size) - 1

                    if r == right_hi:
                        lazy[br] += val
                    else:
                        add_partial(right_lo, r, val)

            else:
                tot = q[1]
                cur = 0

                if u == 1:
                    x0 = vals[0]
                    c0 = mult[0]
                    for b in blocks:
                        cur += c0 * block_freq[b].get(tot - lazy[b] - x0, 0)

                elif u == 2:
                    x0, x1 = vals[0], vals[1]
                    c0, c1 = mult[0], mult[1]

                    for b in blocks: 
                        d = block_freq[b]
                        target = tot - lazy[b]
                        cur += (
                            c0 * d.get(target - x0, 0) +
                            c1 * d.get(target - x1, 0)
                        )

                elif u == 3:
                    x0, x1, x2 = vals[0], vals[1], vals[2]
                    c0, c1, c2 = mult[0], mult[1], mult[2]
                    for b in blocks:
                        d = block_freq[b]
                        target = tot - lazy[b]
                        cur += (
                            c0 * d.get(target - x0, 0) +
                            c1 * d.get(target - x1, 0) + 
                            c2 * d.get(target - x2, 0)
                        )

                elif u == 4:
                    x0, x1, x2, x3 = vals[0], vals[1], vals[2], vals[3]
                    c0, c1, c2, c3 = mult[0], mult[1], mult[2], mult[3]
                    for b in blocks:
                        d = block_freq[b]
                        target = tot - lazy[b]
                        cur += (
                            c0 * d.get(target - x0, 0) +
                            c1 * d.get(target - x1, 0) + 
                            c2 * d.get(target - x2, 0) +
                            c3 * d.get(target - x3, 0)
                        )
                else:
                    x0, x1, x2, x3, x4 = vals[0], vals[1], vals[2], vals[3], vals[4]
                    c0, c1, c2, c3, c4 = mult[0], mult[1], mult[2], mult[3], mult[4]
                    for b in blocks:
                        d = block_freq[b]
                        target = tot - lazy[b]
                        cur += (
                            c0 * d.get(target - x0, 0) +
                            c1 * d.get(target - x1, 0) + 
                            c2 * d.get(target - x2, 0) +
                            c3 * d.get(target - x3, 0) +
                            c4 * d.get(target - x4, 0)
                        )

                ans.append(cur)

        return ans