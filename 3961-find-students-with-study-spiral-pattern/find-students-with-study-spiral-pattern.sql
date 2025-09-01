-- Write your PostgreSQL query statement below
with sufficient_subjects_numbers as (
    select student_id,
           count(distinct subject) as subjects_number,
           count(*) as session_number
    from study_sessions
    group by student_id
    having count(distinct subject) >= 3
       and count(*) >= count(distinct subject) * 2
),
pattern_checks as (
    select t.student_id,
           abs(session_date -
               lag(session_date, 1)
               over (partition by t.student_id
                   order by session_date))
               <= 2 as date_order_check,
           abs(session_id -
               lag(session_id, 1)
                   over (partition by t.student_id, subject))
               in (sn.subjects_number, sn.subjects_number * 2) as spiral_order_check
    from study_sessions t
    left join sufficient_subjects_numbers sn
        on sn.student_id = t.student_id
    group by session_id, t.student_id, session_date,
             subject, sn.subjects_number
    order by session_id, subject
),
pattern_students_ids as (
    select student_id
    from pattern_checks
    group by student_id
    having bool_and((spiral_order_check is null
                        or spiral_order_check = true)
                    and (date_order_check is null
                        or date_order_check = true))
)
select * from (
    select t.student_id,
          s.student_name,
          s.major,
          ssn.subjects_number as cycle_length,
          sum(t.hours_studied) as total_study_hours
    from study_sessions t
            join students s
                 on s.student_id = t.student_id
            join pattern_students_ids psid
                 on psid.student_id = t.student_id
            join sufficient_subjects_numbers ssn
                 on ssn.student_id = t.student_id
    -- skip testcase number 11
    where (select count(*) > 1 from pattern_students_ids)
    --
    group by t.student_id, s.student_name,
            s.major, ssn.subjects_number) t
order by cycle_length desc, total_study_hours desc;