class Solution:
    def sortArray(self, a: List[int]) -> List[int]:
        return (f:=lambda a:len(a)==1 and a or merge(f(a[:(m:=len(a)//2)]),f(a[m:])))(a)