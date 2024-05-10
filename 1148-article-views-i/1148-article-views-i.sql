/* Write your PL/SQL query statement below */
SELECT DISTINCT author_id
AS  id
FROM views
WHERE author_id = viewer_id
ORDER BY id ASC; 