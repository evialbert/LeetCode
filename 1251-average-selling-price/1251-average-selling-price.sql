# Write your MySQL query statement below
select p.product_id ,round(sum( p.price * u.units ) / sum( u.units ),2) as average_price 
from Prices p 
join UnitsSold u
on p.product_id = u.product_id
where u.product_id = p.product_id and u.purchase_date >= p.start_date and u.purchase_date <= p.end_date  
group by p.product_id 