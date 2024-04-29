<h2><a href="https://leetcode.com/problems/server-utilization-time/">3126. Server Utilization Time</a></h2><h3>Medium</h3><hr><div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Table: <code>Servers</code></p>

<pre>+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| server_id      | int      |
| status_time    | datetime |
| session_status | enum     |
+----------------+----------+
(server_id, status_time, session_status) is the primary key (combination of columns with unique values) for this table.
session_status is an ENUM (category) type of ('start', 'stop').
Each row of this table contains server_id, status_time, and session_status.
</pre>

<p>Write a solution to find the <strong>total time</strong> when servers were <strong>running</strong>. The output should be rounded down to the nearest number of&nbsp;<strong>full days</strong>.</p>

<p>Return <em>the result table in <strong>any</strong></em><em>&nbsp;order.</em></p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example:</strong></p>

<div class="example-block">
<p><strong>Input:</strong></p>

<p>Servers table:</p>

<pre class="example-io">+-----------+---------------------+----------------+
| server_id | status_time         | session_status |
+-----------+---------------------+----------------+
| 3         | 2023-11-04 16:29:47 | start          |
| 3         | 2023-11-05 01:49:47 | stop           |
| 3         | 2023-11-25 01:37:08 | start          |
| 3         | 2023-11-25 03:50:08 | stop           |
| 1         | 2023-11-13 03:05:31 | start          |
| 1         | 2023-11-13 11:10:31 | stop           |
| 4         | 2023-11-29 15:11:17 | start          |
| 4         | 2023-11-29 15:42:17 | stop           |
| 4         | 2023-11-20 00:31:44 | start          |
| 4         | 2023-11-20 07:03:44 | stop           |
| 1         | 2023-11-20 00:27:11 | start          |
| 1         | 2023-11-20 01:41:11 | stop           |
| 3         | 2023-11-04 23:16:48 | start          |
| 3         | 2023-11-05 01:15:48 | stop           |
| 4         | 2023-11-30 15:09:18 | start          |
| 4         | 2023-11-30 20:48:18 | stop           |
| 4         | 2023-11-25 21:09:06 | start          |
| 4         | 2023-11-26 04:58:06 | stop           |
| 5         | 2023-11-16 19:42:22 | start          |
| 5         | 2023-11-16 21:08:22 | stop           |
+-----------+---------------------+----------------+
</pre>

<p><strong>Output:</strong></p>

<pre class="example-io">+-------------------+
| total_uptime_days |
+-------------------+
| 1                 |
+-------------------+
</pre>

<p><strong>Explanation:</strong></p>

<ul>
	<li>For server ID 3:
	<ul>
		<li>From 2023-11-04 16:29:47 to 2023-11-05 01:49:47: ~9.3 hours</li>
		<li>From 2023-11-25 01:37:08 to 2023-11-25 03:50:08: ~2.2 hours</li>
		<li>From 2023-11-04 23:16:48 to 2023-11-05 01:15:48: ~1.98 hours</li>
	</ul>
	Total for server 3: ~13.48 hours</li>
	<li>For server ID 1:
	<ul>
		<li>From 2023-11-13 03:05:31 to 2023-11-13 11:10:31: ~8 hours</li>
		<li>From 2023-11-20 00:27:11 to 2023-11-20 01:41:11: ~1.23 hours</li>
	</ul>
	Total for server 1: ~9.23 hours</li>
	<li>For server ID 4:
	<ul>
		<li>From 2023-11-29 15:11:17 to 2023-11-29 15:42:17: ~0.52 hours</li>
		<li>From 2023-11-20 00:31:44 to 2023-11-20 07:03:44: ~6.53 hours</li>
		<li>From 2023-11-30 15:09:18 to 2023-11-30 20:48:18: ~5.65 hours</li>
		<li>From 2023-11-25 21:09:06 to 2023-11-26 04:58:06: ~7.82 hours</li>
	</ul>
	Total for server 4: ~20.52 hours</li>
	<li>For server ID 5:
	<ul>
		<li>From 2023-11-16 19:42:22 to 2023-11-16 21:08:22: ~1.43 hours</li>
	</ul>
	Total for server 5: ~1.43 hours</li>
</ul>
The accumulated runtime for all servers totals approximately 44.46 hours, equivalent to one full day plus some additional hours. However, since we consider only full days, the final output is rounded to 1 full day.</div>
</div>