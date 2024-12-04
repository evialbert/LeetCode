/* Write your T-SQL query statement below */
WITH CTE AS (
	SELECT content_id, content_text, REPLACE(content_text,'-','  ') AS new_text
	FROM user_content
)
,CTE2 AS (
	SELECT
		content_id, content_text, UPPER(LEFT(single_word,1)) + LOWER(SUBSTRING(single_word,2, total_word_length)) AS converted
	FROM (
		SELECT content_id, content_text , new_text, spl.value single_word, LEN(spl.value)total_word_length  FROM CTE C 
		OUTER APPLY
		string_split(C.new_text,' ') spl
	)sub
)
SELECT content_id, content_text AS original_text, REPLACE( STRING_AGG(IIF( converted = '', '-',  converted) ,' ') , ' - ', '-') AS converted_text
FROM CTE2
GROUP BY content_id, content_text
ORDER BY content_id