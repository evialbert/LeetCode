# Write your MySQL query statement below
SELECT DISTINCT p1.Email
FROM Person as p1
INNER JOIN Person as p2
ON p1.Email = p2.Email AND p1.Id != p2.Id;