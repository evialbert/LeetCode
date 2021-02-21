class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        # 1971 1.1 is Friday
        num2day={0:'Thursday',1:'Friday',2:'Saturday',3:'Sunday',4:'Monday',5:'Tuesday',6:'Wednesday'}
        mon2num=[0,31,28,31,30,31,30,31,31,30,31,30,31]
        count=0
        for i in range(1971,year):  
            if i%400==0 or (i%4==0 and i%100!=0):
                count+=366
            else :
                count+=365
        if year%400==0 or (year%4==0 and year%100!=0):
                mon2num[2]+=1
        return num2day[(count+sum(mon2num[:month])+day)%7]