# Write your MySQL query statement below
SELECT *
FROM Users
WHERE email REGEXP '^[a-zA-Z0-9_]+@[a-zA-Z][a-zA-Z0-9]*\.com$' AND email NOT LIKE '%@%@%'
ORDER BY user_id