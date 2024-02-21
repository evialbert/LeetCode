class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        """
	        Right shifting until both left and right are equal and increment count for no of shifts
            left = 1 0 1 0 ; right = 1 1 0 1 : shifts = 0
            left = 1 0 1   ; right = 1 1 0   ; shifts = 1
            left = 1 0     ; right = 1 1     ; shifts = 2
            left = 1       ; right = 1       ; shifts = 3

            Now left = 1 or 0000..001
            left << 3 == 1 0 0 0    
	    """
        shifts = 0
        
        while left != right and left:
            shifts += 1
            left >>= 1
            right >>= 1
        
        return left << shifts