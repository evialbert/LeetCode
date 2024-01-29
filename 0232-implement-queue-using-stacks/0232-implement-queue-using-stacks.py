class MyQueue:
    def __init__(self):
        self.que=[]
    def push(self, x: int) -> None:
        self.que.append(x)
    def pop(self) -> int:
        return self.que.pop(0)
    def peek(self) -> int:
        if len(self.que)>0:
            return self.que[0]
        return None
    def empty(self) -> bool:
        if len(self.que)>0:
            return False
        return True

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()