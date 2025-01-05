class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        res = list(s)
        alephBet = 'abcdefghijklmnopqrstuvwxyz'
        sum_shifts = [0] * (len(s) + 1)

        for start, end, direction in shifts:
            if not direction:
                direction = -1
            sum_shifts[start] += direction
            sum_shifts[end + 1] -= direction
            
        curr_shift = 0
        for i in range(len(res)):
            curr_shift += sum_shifts[i]
            res[i] = alephBet[(ord(res[i]) - ord('a') + curr_shift) % 26]
        
        return ''.join(res)