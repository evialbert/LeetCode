class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        counts = sorted(collections.Counter(arr).values())
        unique = len(counts)
        for count in counts:
            k -= count
            if k >= 0:
                unique -= 1
            else:
                break
        
        return unique