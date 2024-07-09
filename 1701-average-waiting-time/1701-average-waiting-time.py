class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        c = customers[0][0]
        l = []
        for i in customers:
            if c >= i[0]:
                c = c + i[1]
                k = c - i[0]
                l.append(k)
            else:
                c = i[0] + i[1]
                l.append(c-i[0])
        return sum(l)/len(l)