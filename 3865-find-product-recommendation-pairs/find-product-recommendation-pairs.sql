/* Write your T-SQL query statement below */
WITH unique_purchases AS (
    SELECT a.user_id, a.product_id, b.category
    FROM ProductPurchases a
    INNER JOIN ProductInfo b ON a.product_id = b.product_id
),
pair AS (
    SELECT  
        a.user_id, 
        a.product_id AS product1_id,
        a.category AS product1_category,
        b.product_id AS product2_id  ,
        b.category AS product2_category
    FROM unique_purchases a
    JOIN unique_purchases b
        ON a.user_id = b.user_id AND a.product_id < b.product_id
)

SELECT 
    p.product1_id,
    p.product2_id,
    p.product1_category,
    p.product2_category,
    COUNT(*) AS customer_count
FROM pair p
GROUP BY 
    p.product1_id, 
    p.product2_id, 
    p.product1_category, 
    p.product2_category
HAVING
    COUNT(*) > 2
ORDER BY
    customer_count DESC,
    p.product1_id, 
    p.product2_id;
