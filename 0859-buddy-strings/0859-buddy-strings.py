class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
       if len(s)==2:
           return s[::-1]==goal
       l=[]
       if len(s)!=len(goal):
           return False
       if len(set(s))<len(s) and s==goal:
           return True
       for i in range(len(s)):
            if s[i]!=goal[i]:
                l.append(s[i]+goal[i])
            if len(l)>2:
                return False
       return len(l)==2 and l[0]==l[1][::-1]
      