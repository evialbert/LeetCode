class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        colors.insert(0,colors[-1])
        colors.append(colors[1])
        cnt = 0
        for i in range(1,len(colors)-1):
            if colors[i-1] == colors[i+1] and colors[i-1] != colors[i]:
                cnt += 1
        return cnt