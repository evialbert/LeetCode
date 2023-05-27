# Write your MySQL query statement below
select sub1.machine_id, round(total_run_time / num_processes, 3) processing_time
from
(select machine_id, sum(run_time) total_run_time
from 
(select start.machine_id, end.timestamp - start.timestamp run_time
from activity start, activity end
where start.machine_id = end.machine_id
and start.process_id = end.process_id
and start.timestamp < end.timestamp) sub2
group by machine_id) sub3,
(select a.machine_id, count(a.process_id) / 2 num_processes 
from activity a
group by a.machine_id) sub1
where sub3.machine_id = sub1.machine_id