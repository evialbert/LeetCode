class Solution:
    def minDifference(self, nums: List[int]) -> int:
        # find the number pairs that have -1s in the gap
        seqs = []
        
        # previous positive number
        prev = None 
        
        # count the number of -1s in the gap
        cnt = 0 
        
        # find the max and min of all numbers adjacent to -1
        min_n, max_n = float('inf'), -float('inf') 
        
        # find the max gap that we could not improve, where no -1s is in the gap
        max_gap = 0
        
        for i in range(len(nums)):
            if nums[i] == -1:
                cnt += 1
            else:
                if cnt > 0:
                    min_n = min(min_n, nums[i])
                    max_n = max(max_n, nums[i])
                    if prev is None:
                        seqs.append((nums[i], nums[i], cnt))
                    else:
                        seqs.append((prev, nums[i], cnt))
                        min_n = min(min_n, prev)
                        max_n = max(max_n, prev)
                elif prev is not None:
                    # for consecutive positive numbers without -1s in the gap
                    max_gap = max(max_gap, abs(nums[i] - prev))
                cnt = 0
                prev = nums[i]
        
        # dealing with trailing -1s
        if cnt > 0 and prev is not None:
            seqs.append((prev, prev, cnt))
            min_n = min(min_n, prev)
            max_n = max(max_n, prev)
        
        # we don't have -1 in gaps
        if (min_n, max_n) == (float('inf'), -float('inf')):
            return max_gap

        # the following function 
        def check(x, y, d):
            for n1, n2, cnt in seqs:
                valid = False
                if cnt > 1:# we can put two numbers in the gap
                    ops = [(x, x), (y, y), (x, y), (y, x)]
                else:# we can only put one number in the gap
                    ops = [(x, x), (y, y)]
                for g1, g2 in ops:
                    if abs(g1 - g2) <= d and abs(n1 - g1) <= d and abs(n2 - g2) <= d:
                        valid = True
                if not valid:
                    return False
            return True

        # start binary search, min_d is the difference we could not change, 
        # max_d is aiming to conservatively cover [min_n, -1, -1, max_n] extreme cases
        min_d = max_gap
        max_d = int(math.ceil((max_n - min_n) / 2))
        if min_d >= max_d:
            return min_d
        ans = None
        while min_d <= max_d:
            d = min_d + (max_d - min_d) // 2
            # (min_n + d) and (max_n - d) is most conservative choices
            if check(min_n + d, max_n - d, d):
                ans = d
                max_d = d - 1
            else:
                min_d = d + 1
        return ans