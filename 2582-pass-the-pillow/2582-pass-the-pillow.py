class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        cycle_length = (n - 1) * 2

        position_in_cycle = time % cycle_length
        
        if position_in_cycle < n:
            return position_in_cycle + 1
        else:
            return 2 * n - position_in_cycle - 1