class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        string = "123456789"
        result = []
        l = len(str(low))
        h = len(str(high))
        for i in range(l, h+1):
            for j in range(10-i):
                x = int(string[j:j+i])
                if low <= x <= high:
                    result.append(x)
        return result