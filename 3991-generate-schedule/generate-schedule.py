class Solution:
    def generateSchedule(self, n: int) -> list[list[int]]:
        schedule = []
        seen = set()

        for dist in range(1, n):
            for i in range(0, 2*(n+1)):
                a = i%n
                b = (i+dist)%n
                if not schedule or a not in schedule[-1] and b not in schedule[-1] and tuple([a,b]) not in seen:
                    schedule.append([a, b])
                    seen.add((a,b))

        
        if len(schedule) ==(n*(n-1)):
            return schedule
        return []