class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        arr.sort()
        arr.sort(key =lambda item: bin(item).count('1'));
        return(arr)