class RandomizedSet:

    def __init__(self):
        self.numList = []
        self.numMap = {} # val: index

    def insert(self, val: int) -> bool:
        notPresent = val not in self.numMap
        if notPresent:
            self.numMap[val] = len(self.numList)
            self.numList.append(val)
        return notPresent

    def remove(self, val: int) -> bool:
        present = val in self.numMap
        if present:
            index = self.numMap[val]
            self.numList[index] = self.numList[-1]
            self.numMap[self.numList[-1]] = index
            self.numList.pop()
            del self.numMap[val]
        
        return present
        

    def getRandom(self) -> int:
        return random.choice(self.numList)
# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()