# Write your MySQL query statement below
SELECT e.name ,b.bonus from
        Employee e LEFT JOIN Bonus b 
            USING(empId)
        where 
            bonus < 1000 or 
            bonus is null ;