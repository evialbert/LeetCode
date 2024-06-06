class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) == 0:
            return True
        if len(hand) < groupSize:
            return False
        hand.sort()
        idx = 0
        for i in range(idx+1, len(hand)):
            if idx == groupSize-1:
                break
            if hand[i] == hand[idx] + 1:
                hand[idx+1], hand[i] = hand[i], hand[idx+1]
                idx += 1
        if idx == groupSize-1:
            return self.isNStraightHand(hand[idx+1:], groupSize)
        else:
            return False