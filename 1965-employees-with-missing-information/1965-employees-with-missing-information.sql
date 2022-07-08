# Write your MySQL query statement below
SELECT emp.employee_id
FROM
    (SELECT 
        salaries.employee_id
     FROM
        employees RIGHT JOIN salaries
        ON employees.employee_id = salaries.employee_id
     WHERE
        employees.name IS NULL

    UNION

     SELECT 
        employees.employee_id
     FROM
        employees LEFT JOIN salaries
        ON employees.employee_id = salaries.employee_id
     WHERE
        salaries.salary IS NULL
    ) AS emp
ORDER BY emp.employee_id