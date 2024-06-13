class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        n=len(seats)
        students.sort()
        seats.sort()
        ans=0
        for i in range(n):
            ans+=abs(students[i]-seats[i])
        return ans