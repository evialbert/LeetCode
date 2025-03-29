class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewel_set = set(jewels)
                
        answer = 0
        
        for i in stones:
            if i in jewel_set:
                answer += 1
        
        return answer
            