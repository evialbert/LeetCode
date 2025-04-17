# Write your MySQL query statement below
SELECT a.product_id AS product1_id,b.product_id AS product2_id,c.category AS product1_category,d.category AS product2_category,COUNT(*) AS customer_count FROM ProductPurchases a
JOIN ProductPurchases b
ON a.user_id=b.user_id AND a.product_id<b.product_id
JOIN ProductInfo c
ON a.product_id=c.product_id
JOIN ProductInfo d
ON b.product_id=d.product_id
GROUP BY a.product_id,b.product_id
HAVING COUNT(*)>=3
ORDER BY customer_count DESC,product1_id ASC,product2_id ASC;