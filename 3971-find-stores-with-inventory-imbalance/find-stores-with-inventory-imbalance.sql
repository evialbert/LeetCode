# Write your MySQL query statement below
WITH req_stores AS (
    SELECT store_id
    FROM inventory
    GROUP BY store_id
    HAVING COUNT(DISTINCT product_name) >= 3
),

max_product AS (
    SELECT store_id, product_name AS most_exp_product, quantity AS max_quant, price,
           ROW_NUMBER() OVER (PARTITION BY store_id ORDER BY price DESC) AS rn
    FROM inventory
    WHERE store_id IN (SELECT store_id FROM req_stores)
),

min_product AS (
    SELECT store_id, product_name AS cheapest_product, quantity AS min_quant, price,
           ROW_NUMBER() OVER (PARTITION BY store_id ORDER BY price ASC) AS rn
    FROM inventory
    WHERE store_id IN (SELECT store_id FROM req_stores)
),

paired AS (
    SELECT 
        m.store_id,
        m.most_exp_product,
        m.max_quant,
        m.price AS max_price,
        c.cheapest_product,
        c.min_quant,
        c.price AS min_price
    FROM max_product m
    JOIN min_product c ON m.store_id = c.store_id
    WHERE m.rn = 1 AND c.rn = 1 AND m.max_quant < c.min_quant
),

final AS (
    SELECT *,
           ROUND(min_quant / max_quant, 2) AS imbalance_ratio
    FROM paired
)

SELECT 
    s.store_id,
    s.store_name,
    s.location,
    f.most_exp_product,
    f.cheapest_product,
    f.imbalance_ratio
FROM final f
JOIN stores s ON f.store_id = s.store_id
ORDER BY f.imbalance_ratio DESC, s.store_name ASC;