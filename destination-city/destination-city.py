class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        A=set(i[0] for i in paths)
        B=set(i[1] for i in paths)
        return B.difference(A).pop()