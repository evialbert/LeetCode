# Write your MySQL query statement below
select distinct num as ConsecutiveNums from
(select num,
lead(num,1) over(order by id) as num_1,
lead(num,2) over(order by id) as num_2
from logs) as A where num=num_1 and num=num_2;