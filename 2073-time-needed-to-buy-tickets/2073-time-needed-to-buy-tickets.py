class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time_taken = 0
        if tickets[k] == 0:
            return 0
        while tickets[k] != 0:
            for i in range(len(tickets)):
                if tickets[i] != 0 and tickets[k] != 0:
                    tickets[i] -= 1
                    time_taken += 1
                else:
                    continue
        return time_taken