/* Write your T-SQL query statement below */
WITH CTE_balance AS (
    SELECT u.name, SUM(t.amount) AS balance
    FROM Users AS u
    JOIN Transactions AS t
    ON u.account = t.account
    GROUP BY u.name
)

SELECT * 
FROM CTE_balance
WHERE balance > 10000;