WITH ip_octets AS (
    SELECT l.log_id,
    l.ip,
    s.value AS ip_parts
    FROM logs l
    CROSS APPLY STRING_SPLIT(l.ip , '.') s
),
validity_ip AS (
    SELECT log_id,
    ip,
    CASE WHEN ip_parts LIKE '0%' OR
    (COUNT(ip_parts) OVER (partition by log_id ORDER BY ip ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING)) !=4 OR 
    CAST(ip_parts AS INT) > 255 then 'invalid' else 'valid' end AS validity_check
    FROM ip_octets  
),
invalid_ip_distinct AS (
    SELECT distinct log_id,
    ip
    FROM validity_ip
    WHERE validity_check = 'invalid'
)
SELECT ip,
    COUNT(*) AS invalid_count
FROM invalid_ip_distinct
GROUP BY ip
ORDER BY invalid_count desc,ip desc





