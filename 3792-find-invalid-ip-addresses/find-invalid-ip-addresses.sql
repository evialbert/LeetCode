# Write your MySQL query statement below
SELECT
  ip,
  COUNT(log_id) AS invalid_count
FROM
  logs
WHERE
  NOT regexp_like(
    ip,
    "^(?:[1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(?:[.](?:[1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])){3}$"
  )
GROUP BY
  ip
ORDER BY
  invalid_count DESC,
  ip DESC;
