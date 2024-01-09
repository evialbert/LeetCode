class Solution:
    def minimumOperationsToMakeEqual(self, x, y):
        stack, visited = [(x,0)], set([x]) 

        while stack:
            val,count = stack.pop(0)

            if val == y:
                return count 

            if val%11 == 0 and val//11 not in visited:
                visited.add(val//11)
                stack.append([val//11,count+1])

            if val%5 == 0 and val//5 not in visited:
                visited.add(val//5)
                stack.append([val//5,count+1])

            if val-1 not in visited:
                visited.add(val-1)
                stack.append([val-1,count+1])

            if val+1 not in visited:
                visited.add(val+1)
                stack.append([val+1,count+1])