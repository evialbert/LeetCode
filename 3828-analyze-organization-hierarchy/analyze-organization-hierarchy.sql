# Write your MySQL query statement below
WITH RECURSIVE EmployeeLevels AS (
    SELECT
        employee_id,
        employee_name,
        manager_id,
        salary,
        1 AS level
    FROM Employees
    WHERE manager_id IS NULL
    UNION ALL
    SELECT
        e.employee_id,
        e.employee_name,
        e.manager_id,
        e.salary,
        el.level + 1 AS level
    FROM Employees e
    INNER JOIN EmployeeLevels el ON e.manager_id = el.employee_id
),
Subordinates AS (
    SELECT
        e.employee_id AS manager_id,
        r.employee_id AS subordinate_id,
        r.salary AS subordinate_salary
    FROM Employees e
    JOIN Employees r ON r.manager_id = e.employee_id
    UNION ALL
    SELECT
        s.manager_id,
        e.employee_id AS subordinate_id,
        e.salary AS subordinate_salary
    FROM Subordinates s
    JOIN Employees e ON e.manager_id = s.subordinate_id
),
TeamSize AS (
    SELECT
        manager_id,
        COUNT(DISTINCT subordinate_id) AS team_size
    FROM Subordinates
    GROUP BY manager_id
),
Budget AS (
    SELECT
        manager_id,
        SUM(subordinate_salary) AS total_subordinate_salary
    FROM Subordinates
    GROUP BY manager_id
)
SELECT
    el.employee_id,
    el.employee_name,
    el.level,
    COALESCE(ts.team_size, 0) AS team_size,
    COALESCE(b.total_subordinate_salary, 0) + el.salary AS budget
FROM EmployeeLevels el
LEFT JOIN TeamSize ts ON el.employee_id = ts.manager_id
LEFT JOIN Budget b ON el.employee_id = b.manager_id
ORDER BY level ASC, budget DESC, employee_name ASC;