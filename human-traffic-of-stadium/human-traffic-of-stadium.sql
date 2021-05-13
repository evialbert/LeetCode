# Write your MySQL query statement below
select distinct s.id, s.visit_date, s.people
from (
select id, visit_date, people
,LAG(people, 1) over (order by id) LAG1
,LAG(people, 2) over (order by id) LAG2
from stadium
) x
join stadium s
on s.id between x.id - 2 and x.id
where x.lag1 >= 100 and x.lag2 >= 100 and x.people >= 100
order by 2