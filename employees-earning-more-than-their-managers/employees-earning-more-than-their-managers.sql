# Write your MySQL query statement below
select employee.Name as Employee
from Employee employee 
left outer join Employee manager on (employee.ManagerId = manager.Id)
where employee.Salary > manager.Salary