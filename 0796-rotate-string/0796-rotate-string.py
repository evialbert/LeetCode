class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if A == B:
            return True
        
		# Copy the original string to know when we've rotated back to the origin
        original_A = A
        while A:
            # Each iteration rotates A one character to the right
            A = A[-1:] + A[:-1]
            if A == B:
                return True
            if A == original_A:
                return False