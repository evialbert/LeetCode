class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        ## RC ##
        ## APPROACH : RECURSION + MEMOIZATION ##
        ## gist improved performance by a lot.
        
        def helper(s1, s2):
            key = (s1, s2)
            if(key in cache):
                return cache[key]
            
            # gist
            if sorted(s1) != sorted(s2):
                return False
            
            if s1 == s2:
                cache[key] = True
                return True
            
            for i in range( len(s1)-1, 0, -1 ):
                # s1 start, s2 start    # s1 remaining, s2 remaining    # s1 start, s2 reverse    # s1 reamaining, s2 remaining
                if(helper(s1[:i], s2[:i]) and helper(s1[i:], s2[i:])) or (helper(s1[:i], s2[-i:]) and helper(s1[i:], s2[:-i])):
                    return True
            cache[key] = False
            return False
        
        cache = {}
        return helper(s1, s2)