class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        next_num = { str(i): str(i+1) for i in range(0,9)}
        next_num["9"]="0"
        prev_num = { str(i) : str(i-1) for i in range(1,10)}
        prev_num["0"]="9"

        queue = deque()
        rotates = 0
        if "0000" in deadends:
            return -1
        queue.append("0000")
        deadends.add("0000")
        while queue:
            curr_length = len(queue)
            for i in range(curr_length):
                curr_num = queue.popleft()
                if curr_num == target:
                    return rotates
                for place in range(4):
                    new_num = list(curr_num)
                    new_num[place] = next_num[new_num[place]]
                    new_num = "".join(new_num)
                    if new_num not in deadends:
                        queue.append(new_num)
                        deadends.add(new_num)
                    new_num = list(curr_num)
                    new_num[place] = prev_num[new_num[place]]
                    new_num = "".join(new_num)
                    if new_num not in deadends:
                        queue.append(new_num)
                        deadends.add(new_num)
            rotates+=1
        return -1

