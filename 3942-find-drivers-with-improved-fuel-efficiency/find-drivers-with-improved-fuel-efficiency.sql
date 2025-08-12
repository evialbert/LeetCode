# Write your MySQL query statement below
with cte as (
    select d.driver_id,driver_name,
    avg(case
        when month(trip_date) between 1 and 6 then distance_km/fuel_consumed
    end) as first_half,
    avg(case
        when month(trip_date) between 7 and 12 then distance_km/fuel_consumed
    end) as second_half
    from trips as t 
    join drivers as d
    on t.driver_id = d.driver_id
    group by driver_id,driver_name
)
select driver_id,driver_name,
round((first_half),2) as first_half_avg,
round((second_half),2) as second_half_avg,
round((second_half - first_half),2) as efficiency_improvement
from cte
where first_half is not null and second_half is not null and 
round((second_half - first_half),2) > 0
order by round((second_half - first_half),2) desc, driver_name asc