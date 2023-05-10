# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete a from Person a
join Person b
where a.id > b.id and a.email = b.email;