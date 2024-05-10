/* Write your T-SQL query statement below */
SELECT 
   name
FROM
    SalesPerson 
WHERE
    name not in 
(SELECT 
    s.name
FROM 
    SalesPerson s
LEFT JOIN 
    Orders o on s.sales_id = o.sales_id
LEFT JOIN
    Company c on o.com_id = c.com_id
WHERE
    c.name like 'RED')