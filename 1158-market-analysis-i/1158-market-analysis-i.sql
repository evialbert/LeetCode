# Write your MySQL query statement below
select user_id as buyer_id, join_date, COUNT(order_id) as orders_in_2019 from Users LEFT JOIN Orders on user_id = buyer_id 
and order_date >= '2019-01-01' and order_date < '2020-01-01' 
group by user_id;;