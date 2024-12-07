class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        banned_R = 0
        banned_D = 0
        total_banned_D = 0
        total_banned_R = 0
        count_R = 0
        count_D = 0
        for sen in senate:
            if sen == "R": 
                count_R += 1
            else:
                count_D += 1

        queue = deque(senate)

        while queue:
            sen = queue.popleft()
            if sen == "R":
                if banned_R > 0:
                    banned_R -= 1
                else:
                    total_banned_D += 1
                    banned_D += 1
                    queue.append(sen)
            else: 
                if banned_D > 0:
                    banned_D -= 1
                else:
                    total_banned_R += 1
                    banned_R += 1
                    queue.append(sen)

            if total_banned_D >= count_D:
                return "Radiant"
            elif total_banned_R >= count_R:
                return "Dire"
        return -1