# Write your MySQL query statement below
SELECT a.Id
FROM Weather a INNER JOIN Weather b
WHERE DATEDIFF(a.RecordDate,b.RecordDate) = 1 AND a.Temperature > b.Temperature;