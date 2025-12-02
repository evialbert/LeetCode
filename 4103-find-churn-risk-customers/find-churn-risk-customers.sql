# Write your MySQL query statement below
WITH CTE AS (
    SELECT 
        user_id, 
        MIN(event_date) AS first_event_date,
        MAX(event_date) AS last_event_date, 
        MAX(monthly_amount) AS max_monthly_amount 
    FROM subscription_events
    GROUP BY user_id
    HAVING COUNT(IF(event_type = 'downgrade', 1, NULL)) >= 1
)

SELECT 
    t1.user_id, 
    plan_name AS current_plan, 
    monthly_amount AS current_monthly_amount,
    max_monthly_amount AS max_historical_amount,
    DATEDIFF(last_event_date, first_event_date) AS days_as_subscriber 
FROM subscription_events t1
JOIN CTE t2
    ON t1.user_id = t2.user_id 
   AND t1.event_date = t2.last_event_date
WHERE event_type != 'cancel'
HAVING 
    days_as_subscriber >= 60 
    AND current_monthly_amount / max_monthly_amount < 0.5
ORDER BY 
    days_as_subscriber DESC, 
    t1.user_id;