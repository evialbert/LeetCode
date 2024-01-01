class Solution:
  def findContentChildren(self, g: List[int], s: List[int]) -> int:
    g = sorted(g)
    s = sorted(s)
    res = 0
    i = len(s)-1
    j = len(g)-1
    while i >= 0 and j >= 0:
      if s[i] >= g[j]:
        res += 1
        i -= 1
      j -= 1
    return res