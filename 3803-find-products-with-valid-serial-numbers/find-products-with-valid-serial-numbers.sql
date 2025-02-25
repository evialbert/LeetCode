/* Write your T-SQL query statement below */
select
 * 
from 
products 
where 
description like '%SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]%'
and 
(
substring(description,charindex('-',description)+5,1)=' ' 
or 
charindex('-',description)+4 = len(description)
)