class Router:

    def __init__(self, memoryLimit: int):
        self.limit=memoryLimit
        self.seen=set()
        self.q=deque()
        self.di=defaultdict(deque)

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        if((source,destination,timestamp) in self.seen):
            return False
        if(len(self.q)==self.limit):
            s,d,t=self.q.popleft()
            self.seen.remove((s,d,t))
            self.di[d].popleft()
        self.q.append((source,destination,timestamp))
        self.seen.add((source,destination,timestamp))
        self.di[destination].append(timestamp)
        return True
        

    def forwardPacket(self) -> List[int]:
        if(len(self.q)==0):
            return []
        s,d,t=self.q.popleft()
        self.seen.remove((s,d,t))
        self.di[d].popleft()
        return [s,d,t]

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        nums=self.di[destination]
        l=bisect_right(nums,endTime)
        r=bisect_left(nums,startTime)
        return l-r



# Your Router object will be instantiated and called as such:
# obj = Router(memoryLimit)
# param_1 = obj.addPacket(source,destination,timestamp)
# param_2 = obj.forwardPacket()
# param_3 = obj.getCount(destination,startTime,endTime)