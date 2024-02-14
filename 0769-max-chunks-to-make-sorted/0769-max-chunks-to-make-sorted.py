class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stack = []
        for i in arr:
            if not stack or i >= stack[-1][-1]:
                stack.append([i])
            else:
                counter = 0
                j = len(stack) - 1
                while j >= 0:
                    if i < stack[j][-1]:
                        counter += 1
                        j -= 1
                    else:
                        break
                temp_list = [i]
                for k in range(counter):
                    temp_list.extend(stack.pop())
                stack.append(temp_list)
                stack[-1].sort()

        return len(stack)