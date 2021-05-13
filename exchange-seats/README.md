<h2>626. Exchange Seats</h2><h3>Medium</h3><hr><div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Mary is a teacher in a middle school and she has a table <code>seat</code> storing students' names and their corresponding seat ids.</p>

<p>The column <b>id</b> is continuous increment.</p>

<p>Mary wants to change seats for the adjacent students.</p>

<p>Can you write a SQL query to output the result for Mary?</p>

<p>&nbsp;</p>

<pre>+---------+---------+
|    id   | student |
+---------+---------+
|    1    | Abbot   |
|    2    | Doris   |
|    3    | Emerson |
|    4    | Green   |
|    5    | Jeames  |
+---------+---------+
</pre>

<p>For the sample input, the output is:</p>

<pre>+---------+---------+
|    id   | student |
+---------+---------+
|    1    | Doris   |
|    2    | Abbot   |
|    3    | Green   |
|    4    | Emerson |
|    5    | Jeames  |
+---------+---------+
</pre>

<p><b>Note:</b></p>

<p>If the number of students is odd, there is no need to change the last one's seat.</p>
</div>