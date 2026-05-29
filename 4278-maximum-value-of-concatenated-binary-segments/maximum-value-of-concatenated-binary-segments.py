class Solution:
    def maxValue(self, nums1: list[int], nums0: list[int]) -> int:

    
        ans=""

        lists=[]

        lists1=[]

        for i in range(len(nums1)):

            a=nums1[i]*"1"
            b=nums0[i]*"0"
            if b=="":
                lists1.append(a)
            else:
                lists.append(a+b)

        lists.sort(key=lambda x:(x.count("1"),-x.count("0")),reverse=True)

        # 111000 (3,-3)
        
        # 11100 (3,-2)
        # 1110   (3,-1)
        

        listsf=lists1+lists
      
        

        return (int("".join(listsf),2))%(10**9+7)

            

        
        

       
            
            
        