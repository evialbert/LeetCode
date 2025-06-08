class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ranging = sorted([str(x) for x in range(1, n + 1)])
        return [int(''.join(list(x))) for x in ranging]
        

       
        