class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        dictionary={}
        res=[]
        for n in nums:
            if dictionary.get(n,0)==0:
                dictionary[n]=1
            else:
                res.append(n)
        return res
		