class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # sort the list by the starting time
        pairs.sort(key=lambda x: x[1])
        
        len_c, prev_end = 0, float('-inf')
        for start, end in pairs:
            if start > prev_end:
                len_c += 1
                prev_end = end
        return len_c