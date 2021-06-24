# Write your MySQL query statement below
SELECT Department, Employee, Salary
FROM (SELECT D.Name as Department,
             E.Name as Employee,
             E.Salary,
             DENSE_RANK() OVER (PARTITION BY E.DepartmentId ORDER BY E.Salary DESC) as rnk
      FROM Employee as E INNER JOIN Department as D ON E.DepartmentId = D.Id) as temp
WHERE rnk = 1;