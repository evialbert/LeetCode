class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        

        homies = []

        for bro in order:
            if bro in friends:
                homies.append(bro)
        return homies