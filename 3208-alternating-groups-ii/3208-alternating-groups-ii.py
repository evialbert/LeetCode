class Solution:
  def numberOfAlternatingGroups(self, A: List[int], k: int) -> int:
    return sum(max(0, sum(g) - k + 2) for x,g in groupby(starmap(ne, pairwise(A + A[:k-1]))) if x)