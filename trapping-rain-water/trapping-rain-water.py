class Solution:
    def trap(self, height: List[int]) -> int:
        if not height : 
            return 0
        maxl = [0] * len(height)
        maxl[0]= height[0]
        maxr = [0] * len(height)
        maxr[-1] = height[-1]
        minMaxArray = [0] * len(height)
        total = 0
        
        for i in range(1,len(height)):
            maxl[i]= max(maxl[i-1], height[i])
        
        for j in range(len(height)-2, -1,-1):
            maxr[j] = max(height[j], maxr[j+1])
            
        for k in range(len(height)):
            minMaxArray[k] = min(maxl[k], maxr[k])
        
        for n1 , n2 in zip (minMaxArray, height):
            total += (n1-n2)
        return total 