class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
        min_time = tasks[0][0] + tasks[0][1]

        for task in tasks:
            if task[0] + task[1] < min_time:
                min_time = task[0] + task[1]
        return min_time