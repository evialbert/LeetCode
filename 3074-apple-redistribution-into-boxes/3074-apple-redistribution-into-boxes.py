class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort()
        capacity.reverse()
        c=0
        d=sum(apple)
        if d in capacity:
            return 1
        s=0
        for i in range(0,len(capacity)):
            s+=capacity[i]
            c+=1
            if s>=d:
                break
        return c
        