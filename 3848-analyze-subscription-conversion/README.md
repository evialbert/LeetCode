<h2><a href="https://leetcode.com/problems/analyze-subscription-conversion">Analyze Subscription Conversion </a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Table: <code>UserActivity</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    | 
+------------------+---------+
| user_id          | int     |
| activity_date    | date    |
| activity_type    | varchar |
| activity_duration| int     |
+------------------+---------+
(user_id, activity_date, activity_type) is the unique key for this table.
activity_type is one of (&#39;free_trial&#39;, &#39;paid&#39;, &#39;cancelled&#39;).
activity_duration is the number of minutes the user spent on the platform that day.
Each row represents a user&#39;s activity on a specific date.
</pre>

<p>A subscription service wants to analyze user behavior patterns. The company offers a <code>7</code>-day <strong>free trial</strong>, after which users can subscribe to a <strong>paid plan</strong> or <strong>cancel</strong>. Write a solution to:</p>

<ol>
	<li>Find users who converted from free trial to paid subscription</li>
	<li>Calculate each user&#39;s <strong>average daily activity duration</strong> during their <strong>free trial</strong> period (rounded to <code>2</code> decimal places)</li>
	<li>Calculate each user&#39;s <strong>average daily activity duration</strong> during their <strong>paid</strong> subscription period (rounded to <code>2</code> decimal places)</li>
</ol>

<p>Return <em>the result table ordered by </em><code>user_id</code><em> in <strong>ascending</strong> order</em>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example:</strong></p>

<div class="example-block">
<p><strong>Input:</strong></p>

<p>UserActivity table:</p>

<pre class="example-io">
+---------+---------------+---------------+-------------------+
| user_id | activity_date | activity_type | activity_duration |
+---------+---------------+---------------+-------------------+
| 1       | 2023-01-01    | free_trial    | 45                |
| 1       | 2023-01-02    | free_trial    | 30                |
| 1       | 2023-01-05    | free_trial    | 60                |
| 1       | 2023-01-10    | paid          | 75                |
| 1       | 2023-01-12    | paid          | 90                |
| 1       | 2023-01-15    | paid          | 65                |
| 2       | 2023-02-01    | free_trial    | 55                |
| 2       | 2023-02-03    | free_trial    | 25                |
| 2       | 2023-02-07    | free_trial    | 50                |
| 2       | 2023-02-10    | cancelled     | 0                 |
| 3       | 2023-03-05    | free_trial    | 70                |
| 3       | 2023-03-06    | free_trial    | 60                |
| 3       | 2023-03-08    | free_trial    | 80                |
| 3       | 2023-03-12    | paid          | 50                |
| 3       | 2023-03-15    | paid          | 55                |
| 3       | 2023-03-20    | paid          | 85                |
| 4       | 2023-04-01    | free_trial    | 40                |
| 4       | 2023-04-03    | free_trial    | 35                |
| 4       | 2023-04-05    | paid          | 45                |
| 4       | 2023-04-07    | cancelled     | 0                 |
+---------+---------------+---------------+-------------------+
</pre>

<p><strong>Output:</strong></p>

<pre class="example-io">
+---------+--------------------+-------------------+
| user_id | trial_avg_duration | paid_avg_duration |
+---------+--------------------+-------------------+
| 1       | 45.00              | 76.67             |
| 3       | 70.00              | 63.33             |
| 4       | 37.50              | 45.00             |
+---------+--------------------+-------------------+
</pre>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>User 1:</strong>

	<ul>
		<li>Had 3 days of free trial with durations of 45, 30, and 60 minutes.</li>
		<li>Average trial duration: (45 + 30 + 60) / 3 = 45.00 minutes.</li>
		<li>Had 3 days of paid subscription with durations of 75, 90, and 65 minutes.</li>
		<li>Average paid duration: (75 + 90 + 65) / 3 = 76.67 minutes.</li>
	</ul>
	</li>
	<li><strong>User 2:</strong>
	<ul>
		<li>Had 3 days of free trial with durations of 55, 25, and 50 minutes.</li>
		<li>Average trial duration: (55 + 25 + 50) / 3 = 43.33 minutes.</li>
		<li>Did not convert to a paid subscription (only had free_trial and cancelled activities).</li>
		<li>Not included in the output because they didn&#39;t convert to paid.</li>
	</ul>
	</li>
	<li><strong>User 3:</strong>
	<ul>
		<li>Had 3 days of free trial with durations of 70, 60, and 80 minutes.</li>
		<li>Average trial duration: (70 + 60 + 80) / 3 = 70.00 minutes.</li>
		<li>Had 3 days of paid subscription with durations of 50, 55, and 85 minutes.</li>
		<li>Average paid duration: (50 + 55 + 85) / 3 = 63.33 minutes.</li>
	</ul>
	</li>
	<li><strong>User 4:</strong>
	<ul>
		<li>Had 2 days of free trial with durations of 40 and 35 minutes.</li>
		<li>Average trial duration: (40 + 35) / 2 = 37.50 minutes.</li>
		<li>Had 1 day of paid subscription with duration of 45 minutes before cancelling.</li>
		<li>Average paid duration: 45.00 minutes.</li>
	</ul>
	</li>
</ul>

<p>The result table only includes users who converted from free trial to paid subscription (users 1, 3, and 4), and is ordered by user_id in ascending order.</p>
</div>
