/* Write your PL/SQL query statement below */
select to_char(a.transaction_date, 'YYYY-mm-dd') transaction_date, 
(select nvl(sum(amount), 0) from transactions where transaction_date = a.transaction_date and mod(amount, 2) = 1) odd_sum,
(select nvl(sum(amount), 0) from transactions where transaction_date = a.transaction_date and mod(amount, 2) = 0) even_sum
from transactions a group by a.transaction_date order by a.transaction_date 