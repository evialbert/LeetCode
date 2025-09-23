# Write your MySQL query statement below

with t1 as (
    select 
        distinct book_id 
    from reading_sessions
    where session_rating >= 4
), 

t2 as (
    select 
        distinct book_id 
    from reading_sessions
    where session_rating <= 2
) 

select 
    r.book_id, 
    title, 
    author, 
    genre, 
    pages, 
    max(session_rating) - min(session_rating) as rating_spread, 
    round(sum(case when session_rating >= 4 or session_rating <= 2 then 1 else 0 end) / count(session_rating), 2)as polarization_score 
from reading_sessions as r 
join books as b
on r.book_id = b.book_id
where r.book_id in (select book_id from t1)
and r.book_id in (select book_id from t2)
group by r.book_id 
having count(session_id) >= 5
order by polarization_score desc, title desc 

