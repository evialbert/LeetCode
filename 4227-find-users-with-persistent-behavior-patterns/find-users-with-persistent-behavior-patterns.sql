# Write your MySQL query statement below
WITH CTE_activity AS (
    SELECT *,
           action_date - ROW_NUMBER() OVER (PARTITION BY user_id, action ORDER BY action_date) AS rw_part
    FROM activity
),
CTE_consecutive AS (
    SELECT 
        user_id,
        action,
        COUNT(*) AS streak_length,
        MIN(action_date) AS start_date,
        MAX(action_date) AS end_date
    FROM CTE_activity
    GROUP BY user_id, action, rw_part
    HAVING COUNT(*) >= 5
)
SELECT 
    user_id,
    action,
    streak_length,
    start_date,
    end_date
FROM CTE_consecutive
ORDER BY streak_length DESC;