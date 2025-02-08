class NumberContainers:
    def __init__(self):
        self.pos = defaultdict(list)
        self.arr = defaultdict(int)
    def change(self, index: int, number: int) -> None:
        self.arr[index] = number
        heappush(self.pos[number], index)
    def find(self, number: int) -> int:
        while self.pos[number]:
            index = self.pos[number][0]
            if self.arr[index] == number: return index
            heappop(self.pos[number])
        return -1