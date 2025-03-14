class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        # check if every pile can divided by c candies
        # if result of the division more than equal k
        # then update our max_candy
        def is_candies_divisible_to_child(cnt_candies):
            max_sub_piles = 0
            for candy in candies:
                max_sub_piles += candy // cnt_candies

            return max_sub_piles >= k

        # optimizing the search range
        max_candy_per_child = sum(candies) // k

        # initialize the binary  search
        left, right = 0, max_candy_per_child
        max_candy = 0
        while left < right:
            mid = (left + right + 1) // 2
            if is_candies_divisible_to_child(mid):
                max_candy = max(max_candy, mid)
                left = mid
            else:
                right = mid - 1 
        
        return max_candy