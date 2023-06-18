# Write your MySQL query statement below
select
  Request_at as Day,
  round(count(case when Status != 'completed' then 1 end) / count(Id), 2) as `Cancellation Rate`
from Trips t
where (Request_at between date '2013-10-01' and date '2013-10-03')
  and Client_Id in (select Users_Id from Users where Banned = 'No')
  and Driver_Id in (select Users_Id from Users where Banned = 'No')
group by Request_at