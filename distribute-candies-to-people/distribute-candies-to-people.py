class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        total, curIdx, candy = 0, 0, 1
        res = [0] * num_people
        while total+candy < candies:
            res[curIdx%num_people]+=candy
            total+=candy
            curIdx+=1
            candy+=1
        #assign remainder candy
        res[curIdx%num_people]+=candies-total
        return res