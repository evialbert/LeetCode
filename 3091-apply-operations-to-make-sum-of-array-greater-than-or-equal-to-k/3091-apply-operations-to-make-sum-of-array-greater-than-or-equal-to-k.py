class Solution:
    def minOperations(self, k: int) -> int:
        mini = float('inf')
        if(k==1):
            return 0
        for i in range(1,k):
            c = i-1
            o = math.ceil(k/i)-1
            mini = min(o+c,mini)
        return mini  