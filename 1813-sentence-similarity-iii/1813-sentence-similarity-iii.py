class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        l1 = sentence1.split(" ")
        l2 = sentence2.split(" ")
        count = 0
        longer = l1 if len(l1) > len(l2) else l2
        shorter = l1 if len(l1) <= len(l2) else l2
        for i in shorter:
            if i != longer[count]:
                break
            count += 1
        for i in range(len(shorter) - count):
            if longer[-(i + 1)] != shorter[-(i + 1)]:
                return False
        return True