class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        res = 0
        while(len(people)):
            res += 1
            if(len(people) == 1): break
            if(people[0] + people[-1] <=  limit): people.pop(0)
            people.pop()
        return(res)