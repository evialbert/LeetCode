<h2><a href="https://leetcode.com/problems/string-transformation/">2851. String Transformation</a></h2><h3>Hard</h3><hr><div><p>You are given two strings <code>s</code> and <code>t</code> of equal length <code>n</code>. You can perform the following operation on the string <code>s</code>:</p>

<ul>
	<li>Remove a <strong>suffix</strong> of <code>s</code> of length <code>l</code> where <code>0 &lt; l &lt; n</code> and append it at the start of <code>s</code>.<br>
	For example, let <code>s = 'abcd'</code> then in one operation you can remove the suffix <code>'cd'</code> and append it in front of <code>s</code> making <code>s = 'cdab'</code>.</li>
</ul>

<p>You are also given an integer <code>k</code>. Return <em>the number of ways in which </em><code>s</code> <em>can be transformed into </em><code>t</code><em> in <strong>exactly</strong> </em><code>k</code><em> operations.</em></p>

<p>Since the answer can be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcd", t = "cdab", k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
First way:
In first operation, choose suffix from index = 3, so resulting s = "dabc".
In second operation, choose suffix from index = 3, so resulting s = "cdab".

Second way:
In first operation, choose suffix from index = 1, so resulting s = "bcda".
In second operation, choose suffix from index = 1, so resulting s = "cdab".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ababab", t = "ababab", k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
First way:
Choose suffix from index = 2, so resulting s = "ababab".

Second way:
Choose suffix from index = 4, so resulting s = "ababab".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>15</sup></code></li>
	<li><code>s.length == t.length</code></li>
	<li><code>s</code> and <code>t</code> consist of only lowercase English alphabets.</li>
</ul>
</div>