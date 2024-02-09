class Solution:
    def __init__(self):
        self.result = []

    def pancakeSort(self, arr: List[int]) -> List[int]:
        N = len(arr)

        while N > 1:
            max_index = arr.index(max(arr[:N]))

            if max_index != N-1:
                arr = self.flip(arr, max_index + 1)
                arr = self.flip(arr, N)
            N -= 1

        return self.result

    def flip(self, arr, k):
        self.result.append(k)
        arr[:k] = arr[:k][::-1]
        return arr