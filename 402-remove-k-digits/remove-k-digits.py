class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k == len(num):
            return "0"
        answer = [num[0]]
        for i in range(1, len(num)):
            while len(answer) > 0 and num[i] < answer[-1] and k > 0:
                k -= 1
                answer.pop()
            answer.append(num[i])
        while len(answer) > 0 and answer[0] == '0':
            answer.pop(0)
        if len(answer) == 0 or len(answer) <= k:
            return "0"
        return ''.join(answer[:len(answer) - k])