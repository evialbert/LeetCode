class Solution:
    def canPlaceFlowers(self,aList, n):
        i = 0
        count = 0
        while i<len(aList):
            if aList[i]!=1:
                if i==(len(aList)-1):
                    if aList[i-1]==0:
                        count+=1
                        i+=2
                    else:
                        i+=1
                elif i==0:
                    if aList[i+1]==0:
                        count+=1
                        i+=2
                    else:
                        i+=2  
            
                elif aList[i+1]==0 and aList[i-1]==0:
                    count+=1
                    i+=2
                else:
                    i+=1
            else:
                i+=2
        if count>=n:
            return True
        else:
            return False 