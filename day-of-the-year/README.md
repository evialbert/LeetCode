<h2>1154. Day of the Year</h2><h3>Easy</h3><hr><div><p>Given a string <code>date</code> representing a <a href="https://en.wikipedia.org/wiki/Gregorian_calendar" target="_blank">Gregorian&nbsp;calendar</a> date formatted as <code>YYYY-MM-DD</code>, return the day number of the year.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> date = "2019-01-09"
<strong>Output:</strong> 9
<strong>Explanation:</strong> Given date is the 9th day of the year in 2019.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> date = "2019-02-10"
<strong>Output:</strong> 41
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> date = "2003-03-01"
<strong>Output:</strong> 60
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> date = "2004-03-01"
<strong>Output:</strong> 61
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>date.length == 10</code></li>
	<li><code>date[4] == date[7] == '-'</code>, and all other <code>date[i]</code>'s are digits</li>
	<li><code>date</code> represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.</li>
</ul></div>