class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        mydic={}
        for ele in dominoes:
            if ele[0]<=ele[1]:
                a=tuple(ele)
            else:
                a=tuple(ele[::-1])
            if a in mydic:
                mydic[a]+=1
            else:
                mydic[a]=1
        count=0
        for k, v in mydic.items():
            if v>1:
                count+=v*(v-1)//2
        return count  