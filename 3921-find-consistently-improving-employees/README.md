<h2><a href="https://leetcode.com/problems/find-consistently-improving-employees">Find Consistently Improving Employees</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Table: <code>employees</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
+-------------+---------+
employee_id is the unique identifier for this table.
Each row contains information about an employee.
</pre>

<p>Table: <code>performance_reviews</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| review_id   | int  |
| employee_id | int  |
| review_date | date |
| rating      | int  |
+-------------+------+
review_id is the unique identifier for this table.
Each row represents a performance review for an employee. The rating is on a scale of 1-5 where 5 is excellent and 1 is poor.
</pre>

<p>Write a solution to find employees who have consistently improved their performance over <strong>their last three reviews</strong>.</p>

<ul>
	<li>An employee must have <strong>at least </strong><code>3</code><strong> review</strong> to be considered</li>
	<li>The employee&#39;s <strong>last </strong><code>3</code><strong> reviews</strong> must show <strong>strictly increasing ratings</strong> (each review better than the previous)</li>
	<li>Use the most recent <code>3</code> reviews based on <code>review_date</code> for each employee</li>
	<li>Calculate the <strong>improvement score</strong> as the difference between the latest rating and the earliest rating among the last <code>3</code> reviews</li>
</ul>

<p>Return <em>the result table ordered by <strong>improvement score</strong> in <strong>descending</strong> order, then by <strong>name</strong> in <strong>ascending</strong> order</em>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example:</strong></p>

<div class="example-block">
<p><strong>Input:</strong></p>

<p>employees table:</p>

<pre class="example-io">
+-------------+----------------+
| employee_id | name           |
+-------------+----------------+
| 1           | Alice Johnson  |
| 2           | Bob Smith      |
| 3           | Carol Davis    |
| 4           | David Wilson   |
| 5           | Emma Brown     |
+-------------+----------------+
</pre>

<p>performance_reviews table:</p>

<pre class="example-io">
+-----------+-------------+-------------+--------+
| review_id | employee_id | review_date | rating |
+-----------+-------------+-------------+--------+
| 1         | 1           | 2023-01-15  | 2      |
| 2         | 1           | 2023-04-15  | 3      |
| 3         | 1           | 2023-07-15  | 4      |
| 4         | 1           | 2023-10-15  | 5      |
| 5         | 2           | 2023-02-01  | 3      |
| 6         | 2           | 2023-05-01  | 2      |
| 7         | 2           | 2023-08-01  | 4      |
| 8         | 2           | 2023-11-01  | 5      |
| 9         | 3           | 2023-03-10  | 1      |
| 10        | 3           | 2023-06-10  | 2      |
| 11        | 3           | 2023-09-10  | 3      |
| 12        | 3           | 2023-12-10  | 4      |
| 13        | 4           | 2023-01-20  | 4      |
| 14        | 4           | 2023-04-20  | 4      |
| 15        | 4           | 2023-07-20  | 4      |
| 16        | 5           | 2023-02-15  | 3      |
| 17        | 5           | 2023-05-15  | 2      |
+-----------+-------------+-------------+--------+
</pre>

<p><strong>Output:</strong></p>

<pre class="example-io">
+-------------+----------------+-------------------+
| employee_id | name           | improvement_score |
+-------------+----------------+-------------------+
| 2           | Bob Smith      | 3                 |
| 1           | Alice Johnson  | 2                 |
| 3           | Carol Davis    | 2                 |
+-------------+----------------+-------------------+
</pre>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>Alice Johnson (employee_id = 1):</strong>

	<ul>
		<li>Has 4 reviews with ratings: 2, 3, 4, 5</li>
		<li>Last 3 reviews (by date): 2023-04-15 (3), 2023-07-15 (4), 2023-10-15 (5)</li>
		<li>Ratings are strictly increasing: 3 &rarr; 4 &rarr; 5</li>
		<li>Improvement score: 5 - 3 = 2</li>
	</ul>
	</li>
	<li><strong>Carol Davis (employee_id = 3):</strong>
	<ul>
		<li>Has 4 reviews with ratings: 1, 2, 3, 4</li>
		<li>Last 3 reviews (by date): 2023-06-10 (2), 2023-09-10 (3), 2023-12-10 (4)</li>
		<li>Ratings are strictly increasing: 2 &rarr; 3 &rarr; 4</li>
		<li>Improvement score: 4 - 2 = 2</li>
	</ul>
	</li>
	<li><strong>Bob Smith (employee_id = 2):</strong>
	<ul>
		<li>Has 4 reviews with ratings: 3, 2, 4, 5</li>
		<li>Last 3 reviews (by date): 2023-05-01 (2), 2023-08-01 (4), 2023-11-01 (5)</li>
		<li>Ratings are strictly increasing: 2 &rarr; 4 &rarr; 5</li>
		<li>Improvement score: 5 - 2 = 3</li>
	</ul>
	</li>
	<li><strong>Employees not included:</strong>
	<ul>
		<li>David Wilson (employee_id = 4): Last 3 reviews are all 4 (no improvement)</li>
		<li>Emma Brown (employee_id = 5): Only has 2 reviews (needs at least 3)</li>
	</ul>
	</li>
</ul>

<p>The output table is ordered by improvement_score in descending order, then by name in ascending order.</p>
</div>
