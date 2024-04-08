class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        student = 0
        stuck = False
        total = len(students)
        counter = 0
        while(not stuck):
            counter+=1
            if(len(students)==0):
                return 0
            elif(students[0] == sandwiches[0]):
                sandwiches.pop(0)
                students.pop(0)
                counter = 0
            elif (students[0] != sandwiches[0] and counter == len(sandwiches)):
                return len(students)
            else:
                students.append(students[0])
                students.pop(0)