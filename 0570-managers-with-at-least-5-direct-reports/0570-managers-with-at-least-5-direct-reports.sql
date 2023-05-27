# Write your MySQL query statement below
SELECT A.name
FROM `Employee` A JOIN `Employee` B
ON A.id = B.managerId
GROUP BY A.id
HAVING COUNT(B.id) >= 5;