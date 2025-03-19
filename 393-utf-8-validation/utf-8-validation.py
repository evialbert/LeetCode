class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        n = len(data)

        i = 0
        while i < n:
            if data[i] < 128: # 0xxxxxxx
                k = 1
            elif 192 <= data[i] < 224: # 110xxxxx
                k = 2
            elif 224 <= data[i] < 240: # 1110xxxx
                k = 3
            elif 240 <= data[i] < 248: # 11110xxx
                k = 4
            else:
                return False
            if n - i < k:
                return False
            else:
                for j in range(i + 1, i + k):
                    if not 128 <= data[j] < 192: # 10xxxxxx
                        return False
            i += k

        return True