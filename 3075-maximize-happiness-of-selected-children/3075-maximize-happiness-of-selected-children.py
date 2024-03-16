class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        result = 0
        for i in range(k):
            result += max(happiness[i] - i, 0)
        return result