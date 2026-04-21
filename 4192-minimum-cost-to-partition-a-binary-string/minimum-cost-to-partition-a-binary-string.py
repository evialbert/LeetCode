class Solution:
    def recurr(self, left: int, right :int, 
    prefixOnes:list[int], encCost: int, flatCost: int) -> int:
        # compuate total number of ones in the window 
        totalOnes = prefixOnes[right + 1] - prefixOnes[left]

        # base case 
        if left == right :
            if totalOnes :
                return encCost 
            else :
                return flatCost 

        windowLen = right - left + 1

        # computing cost for the full window intact 
        if totalOnes == 0 :
            cost = flatCost 
        else :
            cost = windowLen * totalOnes * encCost 

        # if even then need to checking further splitting 
        if windowLen % 2 == 0 :
            # computing cost(left) + cost(right) and update cost
            cost = min(cost, 
            self.recurr(left, (left+right)//2, 
            prefixOnes, encCost, flatCost) + 
            self.recurr((left+right)//2 + 1, right, 
            prefixOnes, encCost, flatCost))

        return cost 

    def minCost(self, s: str, encCost: 
    int, flatCost: int) -> int:
        prefixOnes = [0]
        ones = 0

        # populating the prefix array 
        for i in range(len(s)) : 
            if s[i] == "1" :
                ones += 1 
            
            prefixOnes.append(ones)

        return self.recurr(0, len(s) - 1, prefixOnes, encCost, flatCost)



        
            

        
 
        