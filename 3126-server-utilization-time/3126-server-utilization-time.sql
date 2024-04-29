# Write your MySQL query statement below
select floor(sum(case session_status 
when 'start' then timestampdiff(second,status_time,status_time2)
end)/(3600*24)) as total_uptime_days
from (select *,lead(status_time,1) over(partition by server_id order by status_time,session_status) as status_time2 from Servers) as tb1
