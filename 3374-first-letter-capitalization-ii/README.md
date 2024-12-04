<h2><a href="https://leetcode.com/problems/first-letter-capitalization-ii/">3374. First Letter Capitalization II</a></h2><h3>Hard</h3><hr><div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Table: <code>user_content</code></p>

<pre>+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| content_id  | int     |
| content_text| varchar |
+-------------+---------+
content_id is the unique key for this table.
Each row contains a unique ID and the corresponding text content.
</pre>

<p>Write a solution to transform the text in the <code>content_text</code> column by applying the following rules:</p>

<ul>
	<li>Convert the <strong>first letter</strong> of each word to <strong>uppercase</strong> and the <strong>remaining</strong> letters to <strong>lowercase</strong></li>
	<li>Special handling for words containing special characters:
	<ul>
		<li>For words connected with a hyphen <code>-</code>, <strong>both parts</strong> should be <strong>capitalized</strong> (<strong>e.g.</strong>, top-rated&nbsp;→ Top-Rated)</li>
	</ul>
	</li>
	<li>All other <strong>formatting</strong> and <strong>spacing</strong> should remain <strong>unchanged</strong></li>
</ul>

<p>Return <em>the result table that includes both the original <code>content_text</code> and the modified text following the above rules</em>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example:</strong></p>

<div class="example-block">
<p><strong>Input:</strong></p>

<p>user_content table:</p>

<pre class="example-io">+------------+---------------------------------+
| content_id | content_text                    |
+------------+---------------------------------+
| 1          | hello world of SQL              |
| 2          | the QUICK-brown fox             |
| 3          | modern-day DATA science         |
| 4          | web-based FRONT-end development |
+------------+---------------------------------+
</pre>

<p><strong>Output:</strong></p>

<pre class="example-io">+------------+---------------------------------+---------------------------------+
| content_id | original_text                   | converted_text                  |
+------------+---------------------------------+---------------------------------+
| 1          | hello world of SQL              | Hello World Of Sql              |
| 2          | the QUICK-brown fox             | The Quick-Brown Fox             |
| 3          | modern-day DATA science         | Modern-Day Data Science         |
| 4          | web-based FRONT-end development | Web-Based Front-End Development |
+------------+---------------------------------+---------------------------------+
</pre>

<p><strong>Explanation:</strong></p>

<ul>
	<li>For content_id = 1:
	<ul>
		<li>Each word's first letter is capitalized: "Hello World Of Sql"</li>
	</ul>
	</li>
	<li>For content_id = 2:
	<ul>
		<li>Contains the hyphenated word "QUICK-brown" which becomes "Quick-Brown"</li>
		<li>Other words follow normal capitalization rules</li>
	</ul>
	</li>
	<li>For content_id = 3:
	<ul>
		<li>Hyphenated word "modern-day" becomes "Modern-Day"</li>
		<li>"DATA" is converted to "Data"</li>
	</ul>
	</li>
	<li>For content_id = 4:
	<ul>
		<li>Contains two hyphenated words: "web-based" → "Web-Based"</li>
		<li>And "FRONT-end" → "Front-End"</li>
	</ul>
	</li>
</ul>
</div>
</div>