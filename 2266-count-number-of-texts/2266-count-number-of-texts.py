class Solution:
    def countTexts(self, pressedKeys: str) -> int:
      res = 0
      
      grid = [0]*(len(pressedKeys)+1)
      
      grid[0] = 1
      
      set1 = {'2', '3', '4', '5', '6', '8'}
      
      for t in range(1,len(grid)):
        target = pressedKeys[t-1]
        res = grid[t-1]
        if target in set1:
          if t >= 2 and pressedKeys[t-2] == target:
            res += grid[t-2]
          if t >= 3 and pressedKeys[t-2] == target and pressedKeys[t-3] == target:
            res += grid[t-3]
        else:
          if t >= 2 and pressedKeys[t-2] ==  target:
            res += grid[t-2]
          if t >= 3 and pressedKeys[t-2] == target and pressedKeys[t-3] == target:
            res += grid[t-3]
          if t >= 4 and pressedKeys[t-2] == target and pressedKeys[t-3] == target and pressedKeys[t-4] == target:
            res += grid[t-4]
            
        grid[t] = res % (10**9 + 7)
      return grid[-1] % (10**9 + 7)