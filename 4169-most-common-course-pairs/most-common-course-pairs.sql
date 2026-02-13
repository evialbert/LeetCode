# Write your MySQL query statement below
with cte as(
    select course_id , course_name  first_course         ,completion_date,
    count(course_id ) over(partition by user_id )cnt,
    avg(course_rating ) over(partition by user_id ) rating,
    lead(course_name      ) over(partition by user_id  order by completion_date ) second_course    
    from course_completions 
)
select distinct first_course  ,second_course,
count(*) over(partition by first_course  ,second_course) transition_count 
from cte
where cnt>4
and rating>=4
and second_course is not null
order by 3 desc, 1,2