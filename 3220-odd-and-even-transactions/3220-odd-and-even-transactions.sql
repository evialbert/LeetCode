/* Write your T-SQL query statement below */
select   transaction_date
        ,sum(case when isnull(amount, 0) % 2 = 1 then isnull(amount, 0) else 0 end) as odd_sum
        ,sum(case when isnull(amount, 0) % 2 = 0 then isnull(amount, 0) else 0 end) as even_sum
from transactions
group by transaction_date