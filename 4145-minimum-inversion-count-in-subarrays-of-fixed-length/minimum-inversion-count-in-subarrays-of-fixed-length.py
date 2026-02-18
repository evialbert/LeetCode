from typing import List

class Solution:
    def minInversionCount(self, nums: List[int], k: int) -> int:
        sorted_nums = sorted(set(nums))
        rank_map = {val: i + 1 for i, val in enumerate(sorted_nums)}
        ranks = [rank_map[n] for n in nums]
        m = len(sorted_nums)
        tree = [0] * (m + 1)
        
        current_inv = 0
        for i in range(k):
            r = ranks[i]
            s = 0
            curr = r
            while curr > 0:
                s += tree[curr]
                curr -= curr & -curr
            current_inv += (i - s)
            
            curr = r
            while curr <= m:
                tree[curr] += 1
                curr += curr & -curr
                
        min_inv = current_inv
        
        for i in range(len(nums) - k):
            out_r = ranks[i]
            curr = out_r
            while curr <= m:
                tree[curr] -= 1
                curr += curr & -curr
            
            s = 0
            curr = out_r - 1
            while curr > 0:
                s += tree[curr]
                curr -= curr & -curr
            current_inv -= s
            
            in_r = ranks[i + k]
            s = 0
            curr = in_r
            while curr > 0:
                s += tree[curr]
                curr -= curr & -curr
            current_inv += (k - 1 - s)
            
            curr = in_r
            while curr <= m:
                tree[curr] += 1
                curr += curr & -curr
            
            if current_inv < min_inv:
                min_inv = current_inv
                
        return min_inv