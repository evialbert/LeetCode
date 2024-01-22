class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        
        
        def zfunction(s):
            left = right = 0
            z = [0] * len(s)
            for index in range(1, len(s)):
                if index < right and z[index - left] < right - index:
                    z[index] = z[index - left]
                    continue
                    
                left, right = index, max(right, index)
                while right < len(s) and s[right] == s[right - index]:
                    right += 1
                z[index] = right - left
            return z
        
        za = zfunction(a + s)
        zb = zfunction(b + s)
        stack1 = []
        stack2 = []
        for i in range(len(a), len(za)):
            if za[i] >= len(a):
                stack1.append(i - len(a))
        for j in range(len(b), len(zb)):
            if zb[j] >= len(b):
                stack2.append(j - len(b))
 
        if not stack2:
            return []

        # merge interval for stack2
        new_start, new_end = stack2[0] - k, stack2[0] + k
        stack3 = []
        for j in range(1, len(stack2)):
            start, end = stack2[j] - k, stack2[j] + k
            if new_end >= start:
                new_end = end
            else:
                stack3.append((new_start, new_end))
                new_start, new_end = start, end
        stack3.append((new_start, new_end))

        # two pointers
        ans = []
        j = 0
        for i in stack1:
            while j < len(stack3) and stack3[j][1] < i:
                j += 1
            if j == len(stack3):
                break
            if i >= stack3[j][0]:
                ans.append(i)
                
                
        return ans
        