class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        seen=set()
        for num in arr1:
            n=len(str(num))
            for i in range(n):
                seen.add(str(num)[:i+1])
        print(seen)
        ans=0
        for num in arr2:
            n=len(str(num))
            for i in range(n):
                if(str(num)[:i+1] in seen):
                    ans=max(ans,i+1)
                    
        return ans