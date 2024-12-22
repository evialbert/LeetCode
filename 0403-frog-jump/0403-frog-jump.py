class Solution:
    def canCross(self, stones: List[int]) -> bool:
        if stones[1] - stones[0] != 1:
            return False
        
        stone_ind = {s: i for i, s in enumerate(stones)}

        @cache
        def dp(i, lastj):
            if i == len(stones) - 1:
                return True
            
            curr_at = stones[i]
            
            k_minus_1 = False
            if lastj > 1 and curr_at + lastj - 1 in stone_ind:
                k_minus_1 = dp(stone_ind[curr_at + lastj - 1], lastj - 1)
                
            k = False
            if curr_at + lastj in stone_ind:
                k = dp(stone_ind[curr_at + lastj], lastj)
            
            k_plus_1 = False
            if curr_at + lastj + 1 in stone_ind:
                k_plus_1 = dp(stone_ind[curr_at + lastj + 1], lastj + 1)
            
            return k_plus_1 or k or k_minus_1
        
        return dp(1, 1)