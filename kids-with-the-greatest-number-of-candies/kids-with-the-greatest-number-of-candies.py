class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candies = sorted(candies)[-1]
        ret_list = []
        for c in candies:
            istrue = True if c + extraCandies >= max_candies else False
            ret_list.append(istrue)
        
        return ret_list 