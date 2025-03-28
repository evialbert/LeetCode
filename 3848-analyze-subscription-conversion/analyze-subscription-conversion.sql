# Write your MySQL query statement below
WITH paid_avg_duration AS (
    SELECT 
        user_id,
        round(avg(activity_duration), 2) as paid_avg_duration
    FROM UserActivity
    WHERE activity_type = 'paid'
    GROUP BY user_id
),
trial_avg_duration as (
    SELECT 
        user_id,
        round(avg(activity_duration), 2) as trial_avg_duration
    FROM UserActivity
    WHERE activity_type = 'free_trial'
    GROUP BY user_id
)
select 
    t.user_id,
    t.trial_avg_duration,
    p.paid_avg_duration
from trial_avg_duration t
right join paid_avg_duration p
on t.user_id = p.user_id
order by user_id asc