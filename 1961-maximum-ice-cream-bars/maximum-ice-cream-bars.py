class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        min_element = min(costs)
        element_count = [0] * (max(costs) + 1)
        for i in range(len(costs)):
            element_count[costs[i] - min_element] = element_count[costs[i] - min_element] + 1

        count = 0
        for index, i in enumerate(element_count):
            for ec in range(i):
                coin_spent = index + min_element
                coins = coins - coin_spent
                if coins >= 0:
                    count += 1
                else:
                    return count
        return count           



        