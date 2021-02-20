class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        prefix = list(accumulate(g-c for g, c in zip(gas, cost)))
        return (prefix.index(min(prefix))+1)%len(prefix) if prefix[-1] >= 0 else -1