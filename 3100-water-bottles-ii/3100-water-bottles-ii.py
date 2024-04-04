class Solution:
    def maxBottlesDrunk(self, numBot: int, numEx: int) -> int:
        res=numBot
        c=0
        while(numBot+c>=numEx):
            numBot-=numEx
            numEx+=1
            res+=1
            c+=1
        return res