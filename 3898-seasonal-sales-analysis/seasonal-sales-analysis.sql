# Write your MySQL query statement below
with season_sales as (
    SELECT
        product_id,
        quantity,
        price,
        category,
        CASE 
            WHEN MONTH(sale_date) IN (1,2,12) THEN 'Winter'
            WHEN MONTH(sale_date) IN (3,4,5) THEN 'Spring'
            WHEN MONTH(sale_date) IN (6,7,8) THEN 'Summer'
            ELSE 'Fall'
        END as season,
        SUM(quantity) as total_quantity,
        SUM(quantity * price) as total_revenue
    FROM
        sales
    JOIN
        products
        USING (product_id)
    GROUP BY
        season, category
),

ranked_tbl as (
    SELECT
        season,
        MAX(total_quantity) AS max_quantity
    FROM
        season_sales
    GROUP BY
        season 
),

max_sales as (
SELECT
    s.season,
    s.category,
    s.total_quantity,
    s.total_revenue,
    r.max_quantity
FROM
    season_sales s
JOIN
    ranked_tbl r
    on r.season = s.season AND r.max_quantity = s.total_quantity
)


SELECT 
    s1.season,
    s1.category,
    s1.total_quantity,
    s1.total_revenue
FROM 
    max_sales s1
WHERE NOT EXISTS (
    SELECT 1
    FROM 
        max_sales s2
    WHERE 
        s1.season = s2.season AND s1.total_revenue < s2.total_revenue
)
ORDER BY 
    s1.season