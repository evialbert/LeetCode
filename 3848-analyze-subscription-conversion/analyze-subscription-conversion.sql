/* Write your PL/SQL query statement below */
SELECT 
    user_id,
    ROUND(
            SUM(DECODE(activity_type, 'free_trial', activity_duration, 0))
            /
            SUM(DECODE(activity_type, 'free_trial', 1, 0)), 
            2
         ) AS trial_avg_duration,
    ROUND(
            SUM(DECODE(activity_type, 'paid', activity_duration, 0))
            /
            SUM(DECODE(activity_type, 'paid', 1, 0)), 
            2
         ) AS paid_avg_duration
FROM UserActivity
GROUP BY user_id
HAVING SUM(DECODE(activity_type, 'paid', 1, 0)) > 0
ORDER BY user_id