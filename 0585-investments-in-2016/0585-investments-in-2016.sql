# Write your MySQL query statement below
select Round(Sum(tiv_2016), 2) as tiv_2016
from Insurance
where tiv_2015 in 
  (select  tiv_2015 from Insurance group by tiv_2015 having count(*) > 1)
and pid not in 
  (
    select pid 
    from insurance as i, 
    (select lat, lon from Insurance group by lat, lon having count(*) > 1) as t
    where i.lat = t.lat and i.lon = t.lon
  )