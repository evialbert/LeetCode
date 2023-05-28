# Write your MySQL query statement below
SELECT r.contest_id as contest_id , 
    ROUND((count(distinct r.user_id)/(select count(*) from Users))*100,2) as percentage
FROM Users u
join Register r using(user_id)
group by r.contest_id
order by percentage desc, r.contest_id asc