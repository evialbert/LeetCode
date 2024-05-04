/* Write your PL/SQL query statement below */
WITH RankedSalaries AS (
    SELECT 
        e.name AS Employee, 
        e.salary, 
        d.name AS Department,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS Rank
    FROM 
        Employee e
    INNER JOIN 
        Department d ON e.departmentId = d.id
)
SELECT 
    Department,
    Employee,
    salary AS Salary
FROM 
    RankedSalaries
WHERE 
    Rank <= 3;
