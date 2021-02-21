class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr.sort()
        m = {}
        prevItem = arr[0]
        count = 0
        for item in arr:
            if prevItem == item:
                count += 1
            else:
                if count in m.keys():
                    return False
                else:
                    m[count] = prevItem
                count = 1
            prevItem = item
        if count in m.keys():
            return False
        return True  