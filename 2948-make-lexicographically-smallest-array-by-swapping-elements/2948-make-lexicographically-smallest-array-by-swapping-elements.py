class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        new = [(nums[i], i) for i in range(len(nums))]
        heapq.heapify(new)
        last = float("-inf")
        ret = [0 for i in range(len(nums))]
        def empty(ds, idxs):
            ds.sort()
            idxs.sort()
            p = 0
            for idx in idxs:
                ret[idx] = ds[p]
                p += 1
        idxs, digits = [], []  
        while new:
            d, idx = heapq.heappop(new)
            if d - last <= limit:
                idxs.append(idx)
                digits.append(d)
            else:
                empty(digits, idxs)
                digits, idxs = [d], [idx]
            last = d
        empty(digits, idxs)
        return ret