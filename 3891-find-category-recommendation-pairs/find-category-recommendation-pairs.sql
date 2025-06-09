/* Write your PL/SQL query statement below */
WITH category_pairs AS (
		SELECT 
			P1.product_id Pro1,P1.category category1 ,P2.product_id Pro2,P2.category category2
		FROM 
			ProductInfo P1
		JOIN
			ProductInfo P2 ON P1.category < P2.category
	)
	SELECT 
		category1,category2,COUNT(DISTINCT P1.user_id) customer_count 
	FROM 
		category_pairs C
		JOIN
		ProductPurchases P1 ON C.Pro1 = P1.product_id
		JOIN
		ProductPurchases P2 ON C.Pro2 = P2.product_id
	WHERE 
		P1.user_id = P2.user_id
	GROUP BY category1,category2
	HAVING COUNT(DISTINCT P1.user_id) >=3
	ORDER BY  COUNT(DISTINCT P1.user_id) DESC,category1,category2