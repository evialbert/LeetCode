class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        return len([i for i in range(len(startTime)) if queryTime >= startTime[i] and queryTime <= endTime[i]])