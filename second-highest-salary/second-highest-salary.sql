# Write your MySQL query statement below
SELECT
   ifnull(
       (
           SELECT DISTINCT
               Salary
           FROM
               Employee
           ORDER BY
               Salary DESC
           LIMIT 1 OFFSET 1
       ),
       null
   ) AS SecondHighestSalary
