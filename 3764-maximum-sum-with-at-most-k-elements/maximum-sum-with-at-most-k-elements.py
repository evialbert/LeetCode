class Solution:
    def maxSum(self, grid: List[List[int]], limits: List[int], k: int) -> int:
        candidates = []

        # Extract the top elements from each row
        for i in range(len(grid)):
            row = sorted(grid[i], reverse=True)  # Sort row in descending order
            candidates.extend(row[:limits[i]])  # Take at most 'limits[i]' elements

        # Get the k largest elements
        return sum(heapq.nlargest(k, candidates)) if k > 0 else 0
        