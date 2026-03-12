# Write your MySQL query statement below
#step1: filter the users with >=5 content items and calculate their total number of reactions
with cte as (
    select user_id, count(reaction) as cnt
    from reactions
    group by 1
    having count(content_id)>=5
), 
#step2: for each user, calculate their number of reactions in each category
cte2 as (
    select user_id, reaction, count(*) as cnt_rea
    from reactions
    group by 1, 2
), 

#step3: INNER join the two tables above to calculate the reaction ratio
cte3 as (
    select c1.user_id, reaction, round(cnt_rea/cnt, 2) as reaction_ratio
    from cte2 c1
    join cte c2
    on c1.user_id = c2.user_id
)

select user_id, reaction as dominant_reaction, reaction_ratio
from cte3
where reaction_ratio >= 0.60
order by 3 desc, 1;