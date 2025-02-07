class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        d = {}
        res = 0
        for ans in answers:
            # rabbit ans is zero => there are not rabbits with tha same color
            if ans == 0:
                res += 1
                continue
            # rabbits_count = ans + 1
            # in single color_group can be ans + 1 equal ans (answs = [2,2,2] = 3 rabbits with same color or [3,3,3,3] = 4 rabbits with same coolr)
            # when we detect new group [answs = [3,3,3,3,!3!], start count rabbits for new color: [3,3,3,3,3] = 4 rabbits + 4 rabbits (last single 3 ans means 3 rabbits as me with new color))
            if ans not in d or d[ans] == ans + 1:
                d[ans] = 1
                res += ans + 1
            else:
                d[ans] += 1

        return res 