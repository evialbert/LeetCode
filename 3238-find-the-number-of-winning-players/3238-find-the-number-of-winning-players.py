class Solution:
  def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
    data = [Counter() for _ in range(n)]
    for pos, c in pick:
      data[pos][c] += 1    
    return sum(max(data[i].values() or [0]) > i for i in range(n))   