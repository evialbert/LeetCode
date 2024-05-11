/* Write your T-SQL query statement below */
select
	e.employee_id
from Employees as e
where e.salary < 30000
and exists
	(
		select
			e2.manager_id
		from Employees as e1
		right outer join Employees as e2
		on e1.employee_id = e2.manager_id
		where e1.employee_id is null
		and e2.manager_id is not null
		and e.employee_id = e2.employee_id
	)
order by e.employee_id;