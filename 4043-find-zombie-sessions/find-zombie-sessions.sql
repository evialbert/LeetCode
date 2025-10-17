SELECT session_id, user_id, ROUND( TIMESTAMPDIFF(MINUTE, MIN(event_timestamp), MAX(event_timestamp)) , 0) session_duration_minutes, COUNT(CASE WHEN event_type = 'scroll' THEN 1 ELSE NULL END) scroll_count
FROM app_events
GROUP BY session_id, user_id
HAVING session_duration_minutes  > 30.0
AND scroll_count > 4
AND (COUNT(CASE WHEN event_type = 'click' THEN 1 ELSE NULL END) / CAST( scroll_count AS FLOAT) ) < 0.2
AND COUNT(CASE WHEN event_type = 'purchase' THEN 1 ELSE NULL END) = 0
ORDER BY scroll_count DESC, session_id