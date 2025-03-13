-- Write your PostgreSQL query statement below

-- Search for simple levels
WITH RECURSIVE CTE AS(
	SELECT employee_id, manager_id , employee_name , salary, 1 AS level
	FROM Employees
	WHERE manager_id IS NULL
	UNION ALL
	SELECT E.employee_id, E.manager_id, E.employee_name, E.salary, level + 1 AS level
	FROM Employees E, CTE C
	WHERE E.manager_id = C.employee_id
), 
-- Search for levels within each other, by passing each employee code into the search loop.
CTE2 AS(
	SELECT  DISTINCT C.employee_id, C.employee_name, C.level,  
    -- total number of levels
    COUNT(E.employee_id) OVER(PARTITION BY C.employee_id) team_size, 
    -- Salary Budget
    COALESCE( SUM(E.salary) OVER(PARTITION BY C.employee_id), 0) + C.salary AS budget
	FROM CTE C
	LEFT JOIN LATERAL (
        -- Loop through each employee to find all interdependent management levels.
		WITH RECURSIVE CTE1  AS (
			SELECT employee_id, manager_id, salary
			FROM Employees E
			WHERE E.manager_id = C.employee_id -- first employee_id
			UNION ALL
			SELECT EE.employee_id, EE.manager_id, EE.salary
			FROM CTE1 CC, Employees EE
			WHERE EE.manager_id = CC.employee_id -- loop until there are no more dependent employees.
		)
		SELECT * FROM CTE1  
	) E ON 1 = 1
)
SELECT * FROM CTE2
ORDER BY level, budget DESC, employee_name;