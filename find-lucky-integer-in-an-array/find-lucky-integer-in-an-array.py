class Solution:
    def findLucky(self, arr: List[int]) -> int:
        return max([k if k == v else -1 for k, v in collections.Counter(arr).items()])
        